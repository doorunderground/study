from PIL import Image
import numpy as np
from picamera2 import Picamera2

import time
# 1. 카메라 초기화
picam2 = Picamera2()
config = picam2.create_video_configuration(
    main={"format": "BGR888", "size": (640, 480)})
picam2.configure(config)
picam2.start()
# 2. 센서 안정화 대기
time.sleep(2)
# 3. NumPy 배열로 직접 캡처 (RGB 포맷)
# Picamera2의 capture_array는 기본적으로 RGB NumPy 배열을 반환합니다.
image_np = picam2.capture_array()
print(image_np.shape)
# 4. NumPy 배열을 PIL 이미지 객체로 변환
# OpenCV와 달리 PIL은 기본적으로 RGB를 사용하므로 색상 변환(cvtColor)이 필요 없습니다.
image_pil = Image.fromarray(image_np)
# 5. 이미지 저장 (인코딩 포함)
# quality 옵션으로 압축률을 조절할 수 있습니다.
image_pil.save("asdf.jpg", "JPEG", quality=90)
# 6. 이후 딥러닝 전처리 및 이미지 처리 수행 (예시)

# 7. 종료 시 카메라 자원 해제
picam2.stop()