# 라프베리파이 실행

import threading
import time
import serial

running = True
data = "11111"

def worker():
    global running, data
    
    ser = serial.Serial('/dev/serial0', 9600, timeout=0.1)  # 1초 → 0.1초
    ser.reset_input_buffer()
    ser.reset_output_buffer()
    
    # 소켓 연결
    while running:
        # 값 읽어오기
        ser.write('\n'.encode())
        data = ser.readline().decode('utf-8').strip()
        time.sleep(0.01)


if __name__ == '__main__':
    th = threading.Thread(target = worker, daemon=True)
    th.start()
    for _ in range(10):
        print(data)
        time.sleep(1)
    running = False
    th.join()
    print("끝.")