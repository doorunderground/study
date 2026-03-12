#%%
import json
import cv2

data = json.load(open('C:\study\CNN_Sleep_Detector\\sleeping_face\\sleeping_face\\train\\images\\images\\w_moon444.json'))
data

# %%
import numpy as np

image = cv2.imread(r'C:\study\CNN_Sleep_Detector\sleeping_face\sleeping_face\train\images\images\w_moon444.jpg')

colors = [(255, 0, 0), (0, 255, 0), (0, 0, 255), (0, 255, 255)]

for i in range(4):
    p = np.array(data['shapes'][i]['points'])
    for pt in p:
        cv2.circle(image, (int(pt[0]), int(pt[1])), 3, colors[i], -1)

cv2.imshow('image', image)
cv2.waitKey(0)

# %%
import numpy as np

p = np.array(data['shapes'][2]['points'])

image = cv2.imread(r'C:\study\CNN_Sleep_Detector\sleeping_face\sleeping_face\train\images\images\w_moon444.jpg')

colors = [(255, 0, 0), (0, 255, 0), (0, 0, 255), (0, 255, 255)]

dst = np.zeros(16)

alt = {'rx':'rs', 'lx':'ls', 'rs':'rs', 'ls':'ls', 'right':'right', 'left':'left'}

#p = (N, 2) 행렬

def sort_ud (p):
    return p[p[:, 1].argsort()].copy()

def sort_lr (p):
    return p[p[:, 0].argsort()].copy()

sorts = { 'rs':sort_ud, 'ls':sort_ud, 'right':sort_lr, 'left':sort_lr}

dst_index = { 'rs':0, 'ls':4, 'right':8, 'lefg':12 }

for shape, color in zip(data['shapes'], colors):
    p = np.array(shape['points']).flatten()
    
    shape['label'] = alt[shape['label']]
    
    if shape['label'] not in dst_index:
        pass # 에러처리
    
    sort_fn = sorts[shape['label']]
    p = sort_fn(p)
    
    i = dst_index[shape['label']]
    
    dst[i:i+4] = p

dst 