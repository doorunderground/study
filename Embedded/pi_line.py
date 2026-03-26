import serial
import time
from gpiozero import Motor

# ===== 시리얼 설정 (test_network.py와 동일) =====
SERIAL_PORT = '/dev/serial0'
BAUD_RATE   = 9600

# ===== 모터 설정 (pi_test_udp.py와 동일) =====
motor_a = Motor(forward=18, backward=17)  # 왼쪽 모터 (장착 방향 반전)
motor_b = Motor(forward=22, backward=27)  # 오른쪽 모터 (장착 방향 반전)

# ===== 속도 / 타이밍 파라미터 =====
BASE_SPEED     = 0.3   # 직진 기본 속도 (0.0 ~ 1.0)
TURN_FACTOR    = 0.12  # 회전 보정 강도 (클수록 회전이 강해짐)
SEARCH_SPEED   = 0.4   # 라인 탐색 회전 속도
SEARCH_TIMEOUT = 1.2   # 라인 미감지 후 탐색 시작까지 대기 (초)
SEARCH_SWING   = 0.3    # 탐색 시 좌/우 방향 유지 시간 (초)


def set_motors(left, right):
    """
    left / right : -1.0 ~ 1.0
    양수 = 물리적 전진 (모터 반전 장착 → .backward()가 전진)
    음수 = 물리적 후진
    """
    for motor, speed in ((motor_a, left), (motor_b, right)):
        if speed > 0:
            motor.backward(min(speed, 1.0))
        elif speed < 0:
            motor.forward(min(abs(speed), 1.0))
        else:
            motor.stop()


def parse_sensors(line: str):
    """
    시리얼로 받은 문자열을 5개 센서값 리스트로 파싱
    예) "11011" → [1, 1, 0, 1, 1]
    유효하지 않으면 None 반환
    """
    line = line.strip()
    if len(line) != 5 or not all(c in '01' for c in line):
        return None
    return [int(c) for c in line]


def get_line_position(vals):
    """
    가중 평균으로 라인의 횡방향 위치 계산
    센서: [S1, S2, S3, S4, S5] (좌→우)
         0 = 라인 감지(검은 선), 1 = 라인 없음
    반환: -2.0(좌 끝) ~ 0.0(중앙) ~ +2.0(우 끝)
          None → 라인 전혀 감지 안 됨
    """
    weights  = [-2, -1, 0, 1, 2]
    detected = [1 - v for v in vals]   # 0→1(감지), 1→0(미감지)
    total    = sum(detected)
    if total == 0:
        return None
    return sum(w * d for w, d in zip(weights, detected)) / total


def follow_line(position):
    """
    위치 오차에 비례해 좌우 속도 보정
    position > 0 (라인이 우측) → 우회전: 좌 빠르게, 우 느리게
    position < 0 (라인이 좌측) → 좌회전: 우 빠르게, 좌 느리게
    """
    correction = position * TURN_FACTOR
    left  = max(0.0, min(1.0, BASE_SPEED + correction))
    right = max(0.0, min(1.0, BASE_SPEED - correction))
    set_motors(left, right)


# ===== 탐색 상태 변수 =====
last_line_time     = time.time()
search_dir         = 0            # 0: 좌 탐색, 1: 우 탐색
search_phase_start = time.time()

# ===== 시리얼 포트 열기 =====
ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=0.1)
ser.flush()

print("=== 라인 트레이서 시작 ===")
print(f"시리얼: {SERIAL_PORT} @ {BAUD_RATE}bps")
print("Ctrl+C 로 종료\n")

try:
    while True:
        raw = ser.readline().decode('utf-8', errors='ignore').strip()

        # 유효한 센서 데이터가 아니면 스킵
        vals = parse_sensors(raw)
        if vals is None:
            continue

        position = get_line_position(vals)
        s_str    = ''.join(map(str, vals))

        # ── 라인 감지 중 ──────────────────────────────────
        if position is not None:
            last_line_time = time.time()
            follow_line(position)

            if position < -0.5:
                state = "◀ 좌회전"
            elif position > 0.5:
                state = "▶ 우회전"
            else:
                state = "▲ 직진  "
            print(f'\r센서: {s_str}  위치: {position:+.2f}  {state}    ', end='', flush=True)

        # ── 라인 미감지 ───────────────────────────────────
        else:
            elapsed = time.time() - last_line_time

            if elapsed < SEARCH_TIMEOUT:
                # 짧은 이탈: 저속 직진 유지 (바로 재발견 기대)
                set_motors(BASE_SPEED * 0.5, BASE_SPEED * 0.5)
                print(f'\r센서: {s_str}  라인 없음 ({elapsed:.1f}s) 저속유지     ', end='', flush=True)

            else:
                # 장시간 이탈: 좌우 스윙으로 라인 탐색
                now           = time.time()
                phase_elapsed = now - search_phase_start

                if phase_elapsed >= SEARCH_SWING:
                    search_dir         = 1 - search_dir   # 방향 전환
                    search_phase_start = now

                if search_dir == 0:
                    set_motors(-SEARCH_SPEED, SEARCH_SPEED)   # 좌 탐색
                    dir_str = "◀ 탐색(좌)"
                else:
                    set_motors(SEARCH_SPEED, -SEARCH_SPEED)   # 우 탐색
                    dir_str = "▶ 탐색(우)"

                print(f'\r센서: {s_str}  {dir_str} ({elapsed:.1f}s)      ', end='', flush=True)

except KeyboardInterrupt:
    print('\n종료')

finally:
    motor_a.stop()
    motor_b.stop()
    ser.close()
