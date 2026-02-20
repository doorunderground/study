import numpy as np
import cv2
import os

board_size = (7,5)

# 체스보드의 실제 3D 좌표를 만드는

squareSize = 1
boardPoints = [] #실세계 좌표값, 보드의 코너를 (0, 0, 0)으로 했을 때의
for y in range(board_size[1]): # 세로 6 
    for x in range(board_size[0]): # 가로 9
        boardPoints.append((x * squareSize, y * squareSize, 0))
boardPoints = np.array(boardPoints, np.float32)

imagePoints = []
objectPoints = []

# for i in range(13):
#     image = cv2.imread(f'left{i+1:02d}.jpg')

##

chess_dir = 'C:\\study\\openCV\\images'

images = []
for file in os.listdir(chess_dir):
    image = cv2.imread(os.path.join(chess_dir, file))
    if image is None:
        continue
    images.append(image)
    h, w, _ = image.shape

    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    ret, corners = cv2.findChessboardCorners(gray, board_size)
    if not ret:
        continue

    
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TermCriteria_COUNT, 40, 0.001)
    corners = cv2.cornerSubPix(gray, corners, (5, 5), (-1, -1), criteria)
    dst = image.copy()
    cv2.drawChessboardCorners(dst, board_size, corners, True)
    imagePoints.append(corners)
    objectPoints.append(boardPoints)

    cv2.imshow('dst', dst)
    cv2.waitKey(0)



_, cameraMatrix, distCoeffs, rvecs, tvecs = cv2.calibrateCamera(objectPoints, imagePoints, (w, h), None, None)
nuCameraMatrix, unknown = cv2.getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, (w, h), 0)
# mapx, mapy = cv.initUndistortRectifyMap(mtx, dist, None, newcameramtx, (w,h), 5)
map1, map2 = cv2.initUndistortRectifyMap(cameraMatrix, distCoeffs, None, nuCameraMatrix, (w, h), cv2.CV_32F)


print(distCoeffs)
print(cameraMatrix)


for image in images:
    dst = cv2.remap(image, map1, map2, cv2.INTER_LINEAR)
    cv2.imshow("rectifed", dst)
    cv2.waitKey(0)
