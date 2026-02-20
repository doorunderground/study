import numpy as np
import cv2
import os

cap = cv2.VideoCapture(0)

num = 0

while 1:
    ret, image = cap.read()
    cv2.imshow('image', image)
    key = cv2.waitKey(10)
    if key == ord('q'):
        break
    if key == ord('s'):
        cv2.imwrite(f'images/image{num}.jpg', image)
    num += 1






