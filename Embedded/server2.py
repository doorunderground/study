import socket
import keyboard
import time
import threading

PI_ADDR = None  # 라즈베리파이 주소 (자동 감지)

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('0.0.0.0', 5002))

print("=== RC카 주행 제어 ===")
print("W: 전진 | S: 후진 | A: 좌회전 | D: 우회전 | 키 없음: 정지 | Q: 종료")
print("라즈베리파이 연결 대기 중...")

def receive_thread():
    """Pi의 최초 접속 메시지를 수신해서 주소를 저장"""
    global PI_ADDR
    while True:
        try:
            data, addr = sock.recvfrom(1024)
            if PI_ADDR != addr:
                PI_ADDR = addr
                print(f'\n라즈베리파이 연결됨: {addr}')
        except Exception:
            break

t = threading.Thread(target=receive_thread, daemon=True)
t.start()

try:
    while True:
        if keyboard.is_pressed('q'):
            print("\n종료")
            break

        if PI_ADDR is None:
            time.sleep(0.05)
            continue

        if keyboard.is_pressed('s'):
            cmd, label = '100,100', '후진'
        elif keyboard.is_pressed('w'):
            cmd, label = '-100,-100', '전진'
        elif keyboard.is_pressed('a'):
            cmd, label = '-100,40', '우회전'
        elif keyboard.is_pressed('d'):
            cmd, label = '40,-100', '좌회전'
        else:
            cmd, label = '0,0', '정지'

        print(f'\r명령: {label} ({cmd})    ', end='', flush=True)
        sock.sendto(cmd.encode(), PI_ADDR)
        time.sleep(0.02)  # 50Hz로 명령 전송


finally:
    sock.close()
