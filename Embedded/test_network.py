#    import serial
#    import time
#    ser = serial.Serial('/dev/serial0', 9600, timeout=0.5)

    # 포트가 열려 있는지 확인 후 버퍼 초기화
#    ser.flush()
#    try:
#        print("시리얼 통신 시작...")
#        while True:
#            message = "aaaaa\n"
#            ser.write(message.encode('utf-8'))
#            print(f"Sent: {message.strip()}")
            
            # 2. 데이터 수신 확인
            #if ser.in_waiting > 0:
            # 라인 단위로 읽어오기
#            line = ser.readline().decode('utf-8').rstrip()
#            print(f"Received: {line}")
#            time.sleep(0.3)

#    except KeyboardInterrupt:
#        print("\n통신을 종료합니다.")
#        ser.close()


import serial
import time

ser = serial.Serial('/dev/serial0', 9600, timeout=0.1)  # 1초 → 0.1초
ser.flush()

try:
    print("시리얼 통신 시작...")
    while True:
        line = ser.readline().decode('utf-8').strip()
        if line:
            print(f"Received: {line}")
        #time.sleep(0.1)
except KeyboardInterrupt:
    print("\n통신을 종료합니다.")
    ser.close()