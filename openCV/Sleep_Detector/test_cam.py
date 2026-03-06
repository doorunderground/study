import cv2
import face_detector
import numpy as np
import pytroch_sd

#import pickle
#rf = pickle.load(open('C:\\study\\openCV\\Sleep_Detector\\rf.pickle', 'rb'))

cam = cv2.VideoCapture(0)
print(cam.isOpened())  # False면 카메라 못 연 것

num = 0
frame_count = 0

while True:
    ret, image = cam.read()
    if ret == 0:
        print("cam failed.")
        break

    dst = image.copy()
    cv2.imshow("dst", dst)
    key = cv2.waitKey(1)
    if key == ord('q'):
        print('Quit')
        break

    frame_count += 1
    if frame_count % 5 != 0:
        continue

    #print("dlib 시작")
    rects, shapes = face_detector.detect(image)
    #print(f"dlib 완료: rects={len(rects)}, shapes={len(shapes)}")
    # face_detector.draw(dst, rects, shapes)

    if len(shapes) == 0:
        continue

    arr = face_detector.to_numpy(rects[0], shapes[0])
    #prob = rf.predict_proba(arr.reshape(1, -1))
    #print("pytorch 시작")
    prob = pytroch_sd.detect(arr)
    print(prob)

    if key == ord('s'):
        arr = face_detector.to_numpy(rects[0], shapes[0])
        np.save(f'data/s_ladofa_{num}.npy', arr)
    if key == ord('w'):
        arr = face_detector.to_numpy(rects[0], shapes[0])
        np.save(f'data/w_ladofa_{num}.npy', arr)
    num += 1