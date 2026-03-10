import cv2
import torch
from torch import nn


# conv + bn + relu
def Conv(in_ch, out_ch):
    return nn.Sequential(
        nn.Conv2d(in_ch, out_ch, kernel_size=3, padding=1),
        nn.BatchNorm2d(out_ch),
        nn.ReLU()
    )

model = nn.Sequential(
    #224
    Conv(3, 32),
    Conv(32, 32),
    Conv(32, 32),
    nn.MaxPool2d(2),
    #112
    Conv(32, 64),
    Conv(64, 64),
    Conv(64, 64),
    nn.MaxPool2d(2),
    #56
    Conv(64, 128),
    Conv(128, 128),
    Conv(128, 128),
    nn.MaxPool2d(2),
    #28
    Conv(128, 256),
    Conv(256, 256),
    Conv(256, 256),
    nn.MaxPool2d(2),
    #14
    Conv(256, 256),
    #7
    Conv(256, 256),

    nn.AdaptiveAvgPool2d(1),
    nn.Flatten(),
    nn.Linear(256, 1),
    nn.Sigmoid()  
)

model.cuda()


model.load_state_dict(torch.load('model.pt'))



detector = cv2.CascadeClassifier()
detector.load('haarcascade_frontalface_default.xml')

cap = cv2.VideoCapture(0)


num = 0
while True:
    ret, image = cap.read()
    image = cv2.flip(image, 1)

    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    faces = detector.detectMultiScale(gray, 1.1, 3, minSize=(30, 30))

    dst = image.copy()
    if len(faces) > 0:
        faces = sorted(faces, key=lambda x:x[2], reverse=True)
        x, y, w, h = faces[0]
        crop = image[y:y+h, x:x+h].copy()
        cv2.rectangle(image, (x, y), (x+w, y+h), (255, 0, 0), 2)

        resized = cv2.resize(crop, (224, 224))
        input = torch.tensor(resized).cuda().float().permute(2, 0, 1).unsqueeze(0) / 255
        with torch.no_grad():
            prob = model(input).item()
        print(prob, 'SLEEP' if prob > 0.5 else '...')


    cv2.imshow('image', image)
    key = cv2.waitKey(1)

    if key == ord('q'):
        break
    elif key == ord('s'):
        cv2.imwrite(f'images/s_ladofa{num}.jpg', crop)
    elif key == ord('w'):
        cv2.imwrite(f'images/w_ladofa{num}.jpg', crop)
    num += 1
