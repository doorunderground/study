import cv2

# OpenCV for face detection
dector = cv2.CascadeClassifier('C:\\study\\CNN_Sleep_Detector\\haarcascade_frontalface_default.xml')

cap = cv2.VideoCapture(0)

num = 0
while True:
    ret, image = cap.read()


    gray = cv2. cvtColor(image, cv2.COLOR_BGR2GRAY)
    faces = dector.detectMultiScale(gray, 1.1, 3, minSize=(30, 30))

    dst = image.copy()

    if len(faces) > 0:
        faces = sorted(faces, key = lambda x:x[2], reverse=True)
        x,y,w,h = faces[0]
        crop = image[y:y+h, x:x+w].copy()
        cv2.rectangle(image, (x, y), (x+w, y+h), (255, 0, 0), 2)
       

    cv2.imshow('image', image)
    key = cv2.waitKey(1)

    if key == ord('q'):
        break
    elif key == ord('s'):
        cv2.imwrite(f'C:\\study\\CNN_Sleep_Detector\\images\\s_moon{num}.jpg', crop)
    elif key == ord('w'):
        cv2.imwrite(f'C:\\study\\CNN_Sleep_Detector\\images\\w_moon{num}.jpg', crop)
    num += 1
