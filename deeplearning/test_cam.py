import cv2
import Face_detect
import numpy as np

cam = cv2.VideoCapture(0)


num = 0

while True:
    ret, image = cam.read()
    if ret == 0:
        print("cam failed.")
        break

    rects, shapes = Face_detect.detect(image)
    dst = image.copy()
    Face_detect.draw(dst, rects, shapes)
    
    cv2.imshow("dst", dst)
    key = cv2.waitKey(1)
    
    if key == ord('q'):
        print('Quit')
        break
    
    if len(shapes) == 0:
        continue
    
    if key == ord('s'):
        arr = Face_detect.to_numpy(rects[0], shapes[0])
        np.save(f'C:\\study\\deeplearning\\data\\s_doorunderground_{num}.npy', arr)
        
    if key == ord('w'):
        arr = Face_detect.to_numpy(rects[0], shapes[0])
        np.save(f'C:\\study\\deeplearning\\data\\s_doorunderground_{num}.npy', arr)

    num += 1
