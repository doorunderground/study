import module_iris
import module_motor

import threading
import time


threads =[
    threading.Thread(target=module_iris.worker, daemon=True),
    threading.Thread(target=module_motor.worker, daemon=True)
]

for th in threads:
    th.start()

try:
    while True:
        key = input('>')
        if key == 'q':
            break
except:
    pass

for th in threads:
    th.running = False
    th.join()