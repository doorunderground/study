import numpy as np
import cv2

board_size = (7, 5)
cap = cv2.VideoCapture(0)

wp = np.array([
    [0, 0, 0],
    [6, 0, 0],
    [0, 4, 0],
    [6, 4, 0]
]).astype(np.float32).reshape(-1, 1, 3)

wp2 = wp.copy()
wp2[:, :, 2] += -4

im = np.array([[790.95082199,   0.         ,624.82284189],
 [  0.        , 802.2623102, 396.11085066],
 [  0.         ,  0.          , 1.        ]])

dist_coeffs = np.zeros((4, 1))

while True:
    ret, image = cap.read()
    if not ret: break

    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    ret, corners = cv2.findChessboardCorners(gray, board_size)
    dst = image.copy()

    if not ret:
        cv2.imshow("dst", image)
        key = cv2.waitKey(1)
        if key == ord('q'):
            break
        continue

    cv2.drawChessboardCorners(dst, board_size, corners, True)

    #35, 1, 2 -> [0, 6, 28, 34]
    ip = corners[[0, 6, 28, 34], :, :]

    _, rvec, tvec = cv2.solvePnP(wp, ip, im, dist_coeffs)

    ip2, _ = cv2.projectPoints(wp2, rvec, tvec, im, dist_coeffs)

    for i in range(4):
        p1 = ip[i].astype(int).flatten()
        p2 = ip2[i].astype(int).flatten()
        cv2.line(dst, p1, p2, (0, 255, 0), 4)
    cv2.polylines(dst, [ip2.astype(int)], True, (0, 0, 255), 4)

    cv2.imshow("dst", dst)
    key = cv2.waitKey(1)
    if key == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
