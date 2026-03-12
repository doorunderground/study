#%%
import cv2
import torch
from torch import nn
import torchvision
import numpy as np
import matplotlib.pyplot as plt

model = torchvision.models.regnet_y_400mf(weights='DEFAULT')
# %%

# BGR - RGB
# resize 244, 244
# scaling 0~255 -> 0~1 ?? : -1~1 ??
# C H W

# B G R
# 0 1 2

image = cv2.imread('dog.jpg')
src = image[..., [2, 1, 0]]     # BGR - RGB
src = cv2.resize(src, (224, 224))  # resize
src = (src / 255 - [0.485, 0.456, 0.406]) / [0.229, 0.224, 0.225]
src = torch.tensor(src).float()
src = src.permute(2, 0, 1).unsqueeze(0) # H W C -> C H W

model.eval()
with torch.no_grad():
    logit = model(src)
logit.argmax()


# %%
