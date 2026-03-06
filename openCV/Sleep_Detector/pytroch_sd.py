import torch
from torch import nn

model = nn.Sequential(
    nn.Linear(136, 256),
    nn.ReLU(),
    nn.Linear(256, 256),
    nn.ReLU(),
    nn.Linear(256, 1),
    nn.Sigmoid()
)

model.load_state_dict(torch.load('model.pt'))

def detect(arr):
    input = torch.tensor(arr).float().reshape(-1, 136)
    with torch.no_grad():
        prob = model(input)
    return prob.item()



