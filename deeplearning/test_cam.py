import cv2
import Face_detect

cam = cv2.VideoCapture(0)

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