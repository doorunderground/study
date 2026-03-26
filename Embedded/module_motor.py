# pc와 통신을 통해 모터를 제어함

import module_iris
import threading
import time
import socket
from gpiozero import Motor

running = True


def worker():
    global running
    
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind(('0.0.0.0', 5001))
    sock.settimeout(1.0)
    
    motor_a = Motor(forward=18, backward=17)
    motor_b = Motor(forward=22, backward=27)
    
    
    # 소켓 연결
    while running:
        addr = ('192.168.0.6', 5002)
        msg = module_iris.data + '\n'
        sock.sendto(msg.encode(), addr)
        
        try:
            data, addr = sock.recvfrom(1024)
            msg = data.decode().strip() #strip -> 공백이나 개행 없애기

            left, right = msg.split(',')
            left, right = int(left), int(right)
            # 모터 제어
            motor_a.forward(left / 100)
            motor_b.forward(right / 100)
        except TimeoutError:
            pass  # 응답 없으면 다음 루프로
        time.sleep(0.1)
    
if __name__ == '__main__':
    th = threading.Thread(target = worker, daemon=True)
    th.start()
    input('엔터를 누르면 종료.')
    
    running = False
    th.join()
    print("끝.")