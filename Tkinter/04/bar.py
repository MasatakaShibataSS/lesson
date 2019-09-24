import tkinter as tk

class MyWindow(tk.Tk):
    def __init__(self, title=None, size=(640, 480)):
        super().__init__()
        self.title(title)
        self.geometry("%dx%d"%(size))
        self.pos = 0
        self.w = size[0]
        self.h = size[1]
        # Barの大きさと位置
        self.bar_height = 20
        self.bar_width = 60
        self.bar_upper_pos = self.h - 80
        self.bar_bottom_pos = self.h - 60
        # キャンバスの生成と配置
        self.canvas  = tk.Canvas(self, width = self.w, height = self.h, bg="#fff")
        self.canvas.place(x=0, y=0)
        # バーを左右に動かすスケールの生成と配置
        self.s1 = tk.Scale(self, label = '', orient = 'h',
            from_=0, to = self.w - self.bar_width,
            command = self.change_pos,
            showvalue = 0,
            length = self.w)
        self.s1.place(x=0, y=self.h - 20);
        # 変数スコアの定義と初期化
        self.score = 100
        # ボールのプロパティ定義
        self.x = 30
        self.y = 10
        self.vx = 7
        self.vy = 5

        self.dia = 20

        # タイマースタート
        self.onTimer()

    def change_pos(self, pos):
#        print(pos)
        self.pos = int(pos)


    def onTimer(self):
        # Clear Canvas
        self.canvas.delete('all')
        h = self.h
        w = self.w
        #bar_upper_pos = self.h - 80
        #bar_bottom_pos = self.h - 60
        #bar_width = 60
        # スコアを表示
        self.score_id = self.canvas.create_text(w/2, h/2, text=str(self.score),
                              font=('FixedSys',48),fill='gray')

        # Update Circle Pos
        self.x += self.vx
        self.y += self.vy
#        print("self.x: ", self.x, "self.y:",self.y)

        if self.x > w or self.x < 0:
            self.vx = - self.vx
        if self.y > h or self.y < 0:
            self.vy = - self.vy
            # score count down 下の壁に当たるとself.vyは(-)になる
            if self.vy < 0:
                self.score -= 1
        #ボールがバーに当たったかの判定(self.y,hは5の倍数と限定)
        #if self.y == h - 80 and (self.pos < self.x < self.pos + 60) and self.vy > 0:
        if self.y==self.bar_upper_pos and (self.pos < self.x < self.pos + self.bar_width) and self.vy > 0:
            self.vy = -self.vy
            # score count up
            if self.vy < 0:
                self.score += 1

        # Draw Circle on Canvas
        id = self.canvas.create_oval(self.x - self.dia/2, self.y - self.dia/2,
                                self.x + self.dia/2, self.y + self.dia/2,
                                fill="red")
        # Draw Bar on Canvas
        #self.canvas.create_rectangle(self.pos, h - 80, self.pos+60, h - 60, fill = 'blue')
        self.canvas.create_rectangle(self.pos, self.bar_upper_pos, self.pos + self.bar_width, self.bar_bottom_pos, fill = 'blue')
        self.after(20, self.onTimer)


def Main():
    w = MyWindow(title="Tkinter Game", size=(420, 400))

    # Call Main loop
    w.mainloop()
if __name__=="__main__":
    Main()
 
