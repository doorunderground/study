import cv2
import dlib
import numpy as np

detector = dlib.get_frontal_face_detector()
predictor = dlib.shape_predictor(r"C:\study\deeplearning\shape_predictor_68_face_landmarks.dat")

#-- flatten
def to_numpy(rect, shape):
    #얼굴 크기가 1x1 이라고 가정
    x1, x2, y1, y2 = rect.left(), rect.right(), rect.top(), rect.bottom()
    w = x2 - x1
    h = y2 - y1

    res = np.zeros((68 * 2,))
    for i in range(68):
        p = shape.part(i)
        res[i * 2] = (p.x - x1) / w
        res[i * 2 + 1] = (p.y - y1) / h

    return res

def detect(image):
    rects = detector(image[..., [2, 1, 0]])
    rects = sorted(rects, key=lambda x : x.right() - x.left(), reverse=True)

    shapes = []
    for rect in rects:
        shape = predictor(image[..., [2, 1, 0]], rect)
        shapes.append(shape)
    return rects, shapes

def draw(dst, rects, shapes):
    for rect, shape in zip(rects, shapes):
        x1, x2, y1, y2 = rect.left(), rect.right(), rect.top(), rect.bottom()
        #턱
        for j in range(17):
            part = shape.part(j)
            cv2.circle(dst, (part.x, part.y), 3, (0, 255, 0), -1)
        for j in range(17, 22):
            part = shape.part(j)
            cv2.circle(dst, (part.x, part.y), 3, (0, 0, 255), -1)
        for j in range(22, 27):
            part = shape.part(j)
            cv2.circle(dst, (part.x, part.y), 3, (255, 0, 0), -1)
        for j in range(27, 36):
            part = shape.part(j)
            cv2.circle(dst, (part.x, part.y), 3, (255, 255, 0), -1)
        for j in range(36, 42):
            part = shape.part(j)
            cv2.circle(dst, (part.x, part.y), 3, (0, 255, 255), -1)
        for j in range(42, 48):
            part = shape.part(j)
            cv2.circle(dst, (part.x, part.y), 3, (255, 0, 255), -1)
        for j in range(48, 68):
            part = shape.part(j)
            cv2.circle(dst, (part.x, part.y), 3, (255, 255, 255), -1)
        cv2.rectangle(dst, (x1, y1), (x2, y2), (0, 0, 255), 3)