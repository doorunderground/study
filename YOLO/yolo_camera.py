import cv2
import numpy as np
from ultralytics import YOLO

#yolo = YOLO('yolo26n.pt')
yolo = YOLO(r'C:\study\YOLO\runs\detect\train4\weights\last.pt')


cap = cv2.VideoCapture(0)

while True:
    ret, image = cap.read()
    
    if not ret:
        break

    result = yolo.predict(image)
    result = result[0].boxes.data.cpu().numpy()


    dst = image.copy()
    for x1, y1, x2, y2, conf, cat in result:
        x1, y1, x2, y2 = np.array([x1, y1, x2, y2]).astype(int)
        label = yolo.names[int(cat)]
        text = f'{label} {conf:.2f}'

        cv2.rectangle(dst, (x1, y1), (x2, y2), (255, 0, 0), 2)
        cv2.putText(dst, text, (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 0, 0), 2)

    cv2.imshow('image', dst)

    key = cv2.waitKey(1)
    if key == ord('q'):
        break

cap.release()