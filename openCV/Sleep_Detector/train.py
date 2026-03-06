#%%
import os
import numpy as np
import torch

x = []
y = []
for root, dirs, filenames in os.walk('C:\\study\\openCV\\Sleep_Detector\\data'):
    for filename in filenames:
        path = root + '/' + filename
        arr = np.load(path)
        x.append(arr)
        if filename[:1] == 's':
            y.append(1)
        else:
            y.append(0)

x = np.array(x)
y = np.array(y)

i = np.random.permutation(len(x))
test_size = len(x) // 9
i_test = i[:test_size]
i_train = i[test_size:]

x_train = x[i_train]
x_test = x[i_test]
y_train = y[i_train]
y_test = y[i_test]

x = x_train.reshape(-1, 68, 2)
N, _, _ = x.shape
x = np.concatenate([x, np.ones((N, 68, 1))], axis = 2)
x.shape


import cv2
mat = cv2.getRotationMatrix2D((0.5, 0.5), 10, 1)
x2 = x @ mat.T
x2.shape

mat = cv2.getRotationMatrix2D((0.5, 0.5), -10, 1)
x3 = x @ mat.T
x3.shape

x_train = np.concatenate([x_train, x2.reshape(-1, 136), x3.reshape(-1, 136)], axis = 0)

y_train = np.concatenate([y_train, y_train, y_train], axis = 0)


#%%
# shape, dtype을 확실하게
# shape -> N, ?
# dtype -> float32

x_train = torch.tensor(x_train).float()
x_test = torch.tensor(x_test).float()
y_train = torch.tensor(y_train).float().reshape(-1, 1)
y_test = torch.tensor(y_test).float().reshape(-1, 1)

# binary classification y.shape = N, 1
#%%

dataset_train = list(zip(x_train, y_train))
dataset_valid = list(zip(x_test, y_test))

loader_train = torch.utils.data.DataLoader(dataset_train,
                                          batch_size = 16,
                                          shuffle = True,
                                          drop_last = True)

loader_valid = torch.utils.data.DataLoader(dataset_valid,
                                          batch_size = 16,
                                          shuffle = True,)

for x , y in loader_train:
    break

x.shape, y.shape, x.dtype, y.dtype


#%% 

# 136 -> 256 -> 256 -> 1
from torch import nn

model = nn.Sequential(
    nn.Linear(136, 256),
    nn.ReLU(),
    nn.Linear(256, 256),
    nn.ReLU(),
    nn.Linear(256, 1),
    nn.Sigmoid()
)


opt = torch.optim.Adam(model.parameters())
loss_fn = torch.nn.BCELoss()

prob = model(x)
loss = loss_fn(prob, y)
loss.backward()

#%%

for epoch in range(300):
    total_loss = 0
    total_acc = 0
    
    for step, (x, y) in enumerate(loader_train):
       
        # 1. feed-forward 
        prob = model(x)
        # 2. loss
        loss = loss_fn(prob, y)
        # 3. grad
        opt.zero_grad()
        loss.backward()
        #4. update
        opt.step()
        
        # metrics
        total_loss += loss.item()
        m_loss = total_loss / (step + 1)
        
        pred = (prob > 0.5).float()
        acc = (pred == y).float().mean() # acc
        total_acc += acc.item()
        m_acc = total_acc / (step + 1)
        
        print(f'\r e={epoch} s ={step} l={m_loss:.4f} acc = {m_acc:.4f}', end='')
    print()
    
    
    total_loss = 0
    total_acc = 0
    
    for step, (x, y) in enumerate(loader_valid):
       
        # 1. feed-forward 
        with torch.no_grad():
            prob = model(x)
        # 2. loss
        loss = loss_fn(prob, y)
     
        
        # metrics
        total_loss += loss.item()
        m_loss = total_loss / (step + 1)
        
        pred = (prob > 0.5).float()
        acc = (pred == y).float().mean() # acc
        total_acc += acc.item()
        m_acc = total_acc / (step + 1)
        
        print(f'\r {" " * 40}  l={m_loss:.4f} acc = {m_acc:.4f}', end='')
    print()
    
    
    # l : 평균 loss(낮을수록 좋음) , acc : 평균 정확도(높을수록 좋음) 
# 60000 / 32(batch_size) = 1875        


#%%

torch.save(model.state_dict(), 'model.pt')


# %%

model.load_state_dict(torch.load('model.pt'))


# %%
