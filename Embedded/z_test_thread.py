# PC 실행

import threading
import time

def func1():
    print(' 1')
    time.sleep(5) # 5s
    print(' 1 종료') 

def func2():
    print(' 2')
    time.sleep(5)
    print(' 2 종료')


# 1. 순차적 -> 10초
# func1()
# func2()


# 2. 동시에 5초만에 하려면?
t1 = threading.Thread(target=func1, daemon=True)
t2 = threading.Thread(target=func2, daemon=True)

t1.start()
t2.start()

t1.join()
t2.join()

print('다 끝 났 따.')

# 결과가 1 -> 2 -> 2종료 -> 1종료 -> 다 끝 났 따
# 이 때는 누가 먼저 끝날 지 모름 

###########################################################

lock = threading.Lock()

def func1():
    print(' 1')
    with lock:
        time.sleep(3) # 3s
        print(' 1 종료') 

def func2():
    print(' 2')
    print('Func1의 종료를 기다림')
    with lock:
        print("Func1이 드디어 끝났다")
        time.sleep(3)
    print(' 2 종료')

t1 = threading.Thread(target=func1, daemon=True)
t2 = threading.Thread(target=func2, daemon=True)

t1.start()
t2.start()

t1.join()
t2.join()

print('다 끝 났 따.')