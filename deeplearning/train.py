import os
import numpy as np

x = []
y = []

BASE_DIR = r'C:\\study\\deeplearning\\data'

for root, dirs, filenames in os.walk(BASE_DIR):
    for filename in filenames:
        if not filename.endswith('.npy'):
            continue  
        
        path = os.path.join(root, filename)
        arr = np.load(path)
        arr = arr.reshape(-1)
        
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

from sklearn.ensemble import RandomForestClassifier
rf = RandomForestClassifier()
rf.fit(x_train, y_train)
pred = rf.predict(x_train)
assert pred.shape == y_train.shape
print((pred == y_train).mean())

pred = rf.predict(x_test)
print((pred == y_test).mean())

import pickle
pickle.dump(rf, open('rf.pickle', 'wb'))