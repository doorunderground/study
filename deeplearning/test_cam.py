import cv2
import Face_detect
import numpy as np
import pickle
rf = pickle.load(open('rf.pickle', 'rb'))

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
    
    # 얼굴이 감지되면 예측 결과 표시
    if len(shapes) > 0:
        arr = Face_detect.to_numpy(rects[0], shapes[0])
        prob = rf.predict_proba(arr.reshape(1, -1))
    
    # 예측 결과를 화면에 표시
        label = f"Class 0: {prob[0][0]:.2f}, Class 1: {prob[0][1]:.2f}"
        cv2.putText(dst, label, (10, 30), cv2.FONT_HERSHEY_SIMPLEX,
                    0.7, (0, 255, 0), 2)
        
    # 예측된 클래스 표시
        predicted_class = prob[0].argmax()
        class_text = f"Predicted: {'Class 1' if predicted_class == 1 else 'Class 0'}"
        cv2.putText(dst, class_text, (10, 60), cv2.FONT_HERSHEY_SIMPLEX,
                    0.7, (0, 255, 0), 2)

        print(f"Probability: {prob}, Predicted: {predicted_class}")
    
    
    
    cv2.imshow("dst", dst)
    key = cv2.waitKey(1)
    
    if key == ord('q'):
        print('Quit')
        break
    
    if len(shapes) == 0:
        continue
    
    # 's' 키 : class 1 데이터 저장
    if key == ord('s'):
        arr = Face_detect.to_numpy(rects[0], shapes[0])
        np.save(f'C:\\study\\deeplearning\\data\\s_doorunderground_{num}.npy', arr)
        print(f'Saved: s_doorunderground_{num}.npy (Class 1)')
        num += 1
        
    # 'w 키 : class 0 데이터 저장
    if key == ord('w'):
        arr = Face_detect.to_numpy(rects[0], shapes[0])
        np.save(f'C:\\study\\deeplearning\\data\\w_doorunderground_{num}.npy', arr)
        print(f'Saved: w_doorunderground_{num}.npy (Class 0)')
        num += 1
    
