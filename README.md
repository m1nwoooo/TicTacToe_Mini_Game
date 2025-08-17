# TicTacToe_Mini_Game
Designed and implemented a physical 3x3 Tic-Tac-Toe game, with the hardware controlled by a Raspberry Pi and the game logic programmed in Python

Arduino & Python Tic-Tac-Toe

새학기맞이주간 행사를 위해 제작된 3x3 하드웨어와 Python GUI를 연동한 틱택토(Tic-Tac-Toe) 게임입니다. 사용자가 직접 만든 3x3 버튼 매트릭스를 누르면 라즈베리파이 디스플레이에 실시간으로 표시됩니다.

## 🛠️ 시스템 구성 및 동작 원리

### 하드웨어 (Arduino)

<img width="768" height="463" alt="image" src="https://github.com/user-attachments/assets/a761f301-1abd-4b85-9348-fe5dfdd3ab61" />

<img width="583" height="425" alt="image" src="https://github.com/user-attachments/assets/cabe2cff-974d-4431-bd5b-4247706adf98" />

### 소프트웨어 (Arduino)

3개의 output 핀(Column)과 3개의 input 핀(Row)을 사용합니다. 

첫 번째 

output 핀(Column)에만 HIGH 신호를 보내고, 나머지 output 핀들은 LOW로 유지합니다. 

이 상태에서 3개의 input 핀(Row)을 모두 읽어 어느 버튼이 눌렸는지 확인합니다.

다음 output 핀(Column)에 HIGH 신호를 보내는 과정을 순차적으로 반복합니다.

이 전체 스캔 과정이 매우 빠른 속도로 반복되므로, 시스템은 어떤 버튼이 눌렸는지 실시간으로 감지할 수 있습니다.

버튼이 눌리면, 해당 위치를 1~9 사이의 숫자로 변환하여 PC로 시리얼 데이터를 전송합니다. 

짧은 시간 내에 여러 번의 입력이 감지되는 것을 방지하기 위해 700ms의 지연시간(debouncing)을 두어 한 번의 입력만 처리하도록 설계되었습니다. 

### 소프트웨어 (Python)

PC에서 실행되는 메인 게임 로직 및 화면 표시를 담당합니다.

pyserial 라이브러리를 통해 Arduino로부터 전송되는 시리얼 데이터를 지속적으로 수신합니다.

tkinter 라이브러리를 사용하여 3x3 격자 형태의 게임 보드를 GUI로 생성합니다.

데이터(1~9)를 수신하면, 이를 격자의 좌표(row, col)로 변환합니다.

현재 플레이어의 턴에 맞춰 해당 좌표의 칸을 빨간색 또는 파란색으로 변경합니다.

한 번 선택된 칸은 다시 선택할 수 없도록 occupied 배열로 상태를 관리합니다.

플레이어의 턴을 자동으로 전환하여 게임을 진행합니다.
