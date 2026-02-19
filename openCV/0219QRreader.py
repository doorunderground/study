import cv2
import numpy as np
import matplotlib.pyplot as plt

image = cv2.imread('C:\\study\\openCV\\qrcode2.png')

gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

_, bin = cv2.threshold(gray, 168, 255, cv2.THRESH_BINARY)
# 이진화 처리
# 픽셀값이 168 초과 -> 255(흰색)
# 픽셀값이 168 이하 -> 0(검정색)

bin = cv2.erode(bin, np.ones((3,3)), iterations = 6)
bin = cv2.dilate(bin, np.ones((3,3)), iterations = 6)
# 침식(erode) -> 팽창(dilate) : 노이즈 제거, 작은 점들을 없애고 주요 형태만 남김


# 이진화된 이미지에서 윤곽선을 검출함
contours, hierarchy = cv2.findContours(bin, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
contours = list(contours)
hierarchy = hierarchy[0]

# bin	이진화 이미지 입력
# cv2.RETR_TREE	모든 윤곽선을 계층 구조(부모-자식 관계)로 검출
# cv2.CHAIN_APPROX_SIMPLE	윤곽선의 꼭짓점 좌표만 저장 (중간 점 생략)


filtered_index = []

dst = np.zeros(image.shape, image.dtype)
# 원본 이미지와 동일한 크기 / 타입의 검정 배경 이미지를 생성

for i in range (len(contours)):
    con = contours[i] # m, 1, 2 
    arclen = cv2.arcLength(con, True)
    # 윤곽선의 둘레 길이를 계산함
    
    if arclen < 100:
        continue
    if arclen > 3000:
        continue    
        
    area = cv2.contourArea(con)
    if area < 1000:
        continue     
    if area > 90000:
        continue
    
    ap_con = cv2.approxPolyDP(con, arclen * 0.03, True)
    
    if len(ap_con) != 4:
        continue
    
    filtered_index.append(i)
    contours[i] = ap_con
    
    cv2.drawContours(dst, contours, i, np.random.randint(64,255, size = 3).tolist(), 3)
    # -> 각 윤곽선마다 다른 색상으로 그려짐





landmarks = []

for i in filtered_index:
    con = contours[i]
    hie = hierarchy[i] # 형 도생 자식 부모 ..의 인덱스
    
    pi = hie[3]
    if pi == -1:
        continue
    p_con = contours[pi]
    if len(p_con) != 4:
        continue
    
    
    ci = hie[2]
    if ci == -1:
        continue
    c_con = contours[ci]
    if len(c_con) != 4:
        continue
    
    cv2.drawContours(dst, contours, i, (0, 255, 255), 3)

    landmarks.append(p_con)
    
    
    
landmarks = [land.reshape(-1, 2) for land in landmarks]

for land in landmarks:
    x = land[:, 0]
    y = land[:, 1]
    lb = (x - y).argmin()
    rt = (x - y).argmax()
    lt = (x + y).argmin()
    rb = (x + y).argmax()
    land[:] = land[[lt, rt, rb, lb]]

rect = np.array([[0, 0], [7, 0], [7, 7], [0, 7]], np.float32)
r1 = rect * 10
r2 = rect * 10 + [300, 0]
r3 = rect * 10 + [0, 300]

dst_points = np.r_[r3, r2, r1].astype(np.float32)
dst_points.shape, dst_points.dtype

src_points = np.r_[landmarks[0].reshape(-1, 2),
                   landmarks[1].reshape(-1, 2),
                   landmarks[2].reshape(-1, 2)].astype(np.float32)
src_points.shape, src_points.dtype
#cornerSubPix

# cv2.getPerspectiveTransform - 정확히 점 4개 넣어주면 계산
mat, _ = cv2.findHomography(src_points, dst_points, cv2.RANSAC)
crop = cv2.warpPerspective(bin, mat, (370, 370))
cv2.imshow('crop', crop)

code = cv2.resize(crop, (37, 37)) > 128
plt.imshow(code)
plt.axis('off')
plt.show()


dst = cv2.resize(dst, None, fx=1, fy=1)
cv2.imshow('image', dst)
cv2.waitKey(0)
