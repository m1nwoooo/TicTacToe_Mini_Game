import serial
import tkinter as tk

py_serial = serial.Serial(port='COM5', baudrate=9600, timeout=1)

window = tk.Tk()
window.title("Tic! Tac! Toe!")
window.geometry("800x640+100+100")

labels = [[None,None,None], [None,None,None], [None,None,None]] #배열 선언
occupied = [[False,False,False], [False,False,False], [False,False,False]] # 이미 눌린곳은 ㄴㄴㄴ

for i in range(3):
    for j in range(3):
        labels[i][j] = tk.Label(window, width=25, height=12, relief="solid")
        labels[i][j].grid(row=i, column=j)

label_a = tk.Label(window, fg="blue", text="임원진: 파란색")
label_b = tk.Label(window, fg="red", text="손님: 빨간색")
label_c = tk.Label(window, fg="black", text="손님 先")
label_a.grid(row=6, column=0)
label_b.grid(row=5, column=0)
label_c.grid(row=4, column=0)

current_player = {"turn": "red"}

def read_serial():
    if py_serial.in_waiting > 0:
        res = py_serial.readline().decode().strip()
        if res.isdigit(): #아직 숫자형 문자열임
            num = int(res) - 1 #캐스팅해주고 보드판에 맞춰 0~8로 변환, 그래야 0행~2열 꼴로 나타냄냄
            row = num // 3
            col = num % 3
            if not occupied[row][col] and num>=0:  
                color = "firebrick2" if current_player["turn"] == "red" else "RoyalBlue1"
                labels[row][col].config(bg=color)
                occupied[row][col] = True
                current_player["turn"] = "blue" if current_player["turn"] == "red" else "red" #턴 넘김
    window.after(100, read_serial)

window.after(100, read_serial)
window.mainloop()
