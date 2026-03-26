import socket
from gpiozero import Motor

# ===== 모터 설정 =====
motor_a = Motor(forward=18, backward=17)  # 왼쪽 모터 (장착 방향 반전)
motor_b = Motor(forward=22, backward=27)  # 오른쪽 모터 (장착 방향 반전)

def control_motor(motor, value):
    """value: -100 ~ 100 → 음수: 후진, 양수: 전진, 0: 정지"""
    if value > 0:
        motor.forward(value / 100)
    elif value < 0:
        motor.backward(abs(value) / 100)
    else:
        motor.stop()

# ===== UDP 설정 =====
PC_IP   = '192.168.0.6'  # PC IP 주소
PC_PORT = 5002

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('0.0.0.0', 8001))
sock.settimeout(0.5)

print('=== RC카 주행 시작 ===')
print(f'PC 서버({PC_IP}:{PC_PORT}) 연결 중...')
print('Ctrl+C 로 종료')

# PC에 한 번만 등록 메시지 전송
sock.sendto(b'hello', (PC_IP, PC_PORT))

try:
    while True:
        try:
            data, _ = sock.recvfrom(1024)
            msg = data.decode().strip()

            left, right = msg.split(',')
            left, right = int(left), int(right)

            control_motor(motor_a, left)
            control_motor(motor_b, right)

            print(f'\r명령 수신: 좌={left:4d} 우={right:4d}  ', end='', flush=True)

        except socket.timeout:
            # 연결 끊기면 재등록 시도
            motor_a.stop()
            motor_b.stop()
            print('\r서버 응답 없음 - 재연결 시도...', end='', flush=True)
            sock.sendto(b'hello', (PC_IP, PC_PORT))

except KeyboardInterrupt:
    print('\n종료')

finally:
    motor_a.stop()
    motor_b.stop()
    sock.close()
