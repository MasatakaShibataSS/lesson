import tkinter as tk
import datetime
import time
import serial
import json
from tkinter import messagebox
import imaplib

SERVER_NAME = "imap.gmail.com"
USERNAME = "masataka.shibata.sss@gmail.com"
PASSWORD = "Sativa5466"

class App:

    def __init__(self, master=None):
        self.master = master
        #時刻設定
        self.frame1 = tk.LabelFrame(master, text='時刻設定')
        self.frame1.pack(anchor='w')
        self.date_time = tk.StringVar()
        self.date_time.set('')
        #時刻設定表示Labelの生成
        tk.Label(self.frame1,textvariable=self.date_time ,width=20).grid(row=0, column=0)

        #設定ボタンの生成
        self.submit1 = tk.Button(self.frame1,text='設定',width=4,command=self.asubmit)
        self.submit1.grid(row=0,column=7)

        #アラーム設定
        self.frm_alarm = tk.LabelFrame(master, text='アラーム　時　　分')
        self.frm_alarm.pack(anchor='w')
        tk.Label(self.frm_alarm, text='　　　　').grid(row=0, column=0)
        self.alm_hh_spin = tk.Spinbox(self.frm_alarm, from_= 0, to= 23, increment=1, width=2)
        self.alm_mm_spin = tk.Spinbox(self.frm_alarm, from_= 0, to= 60, increment=1, width=2)
        self.alm_hh_spin.grid(row=0,column=1)
        self.alm_mm_spin.grid(row=0,column=2)

        #設定ボタンの生成
        self.submit1 = tk.Button(self.frm_alarm,text='設定',width=4,command=self.wsubmit)
        self.submit1.grid(row=0,column=7)

        #タイマー設定
        self.frm_timer = tk.LabelFrame(master, text='タイマー　分　　秒')
        self.frm_timer.pack(anchor='w')
        tk.Label(self.frm_timer, text='　　　　').grid(row=0, column=0)
        self.tm_mm_spin = tk.Spinbox(self.frm_timer, from_= 0, to= 23, increment=1, width=2)
        self.tm_ss_spin = tk.Spinbox(self.frm_timer, from_= 0, to= 60, increment=1, width=2)
        self.tm_mm_spin.grid(row=0,column=1)
        self.tm_ss_spin.grid(row=0,column=2)

        #設定ボタンの生成
        self.submit1 = tk.Button(self.frm_timer,text='設定',width=4,command=self.tsubmit)
        self.submit1.grid(row=0,column=7)

        #Humidity & Temparature
        self.dht_val = tk.StringVar()
        self.dht_val.set('')
        self.frm_dht = tk.LabelFrame(master, text = '湿度 温度')
        self.frm_dht.pack(anchor = 'w')
        tk.Label(self.frm_dht, textvariable = self.dht_val, width=15).grid(row=0, column=0)

        #読取ボタンの生成
        submit = tk.Button(self.frm_dht,text='読取',width=4,command=self.dht_submit)
        submit.grid(row=0,column=1)

        #メッセージEditBox
        self.frm_msg = tk.LabelFrame(master,text='メッセージ：')
        self.frm_msg.pack(anchor='w')
        self.msgEditBox = tk.Entry(self.frm_msg, width=40)
        self.msgEditBox.grid(row=0,column=0)
        self.submit2 = tk.Button(self.frm_msg,text='送信',width=4,command=self.m_submit)
        self.submit2.grid(row=0, column=1)

        self.con = serial.Serial('/dev/ttyACM0',9600)
        # ArduinoClockの初期化終了待ち
        time.sleep(5)

        # ３分おきに未読メールのチェック
        self.update_mail()

    #時刻設定「設定」ボタン処理
    def asubmit(self):
        d= datetime.datetime.now()
        cmd = d.strftime('a,%Y,%m,%d,%H,%M,%S') + '\n'
        buf = bytes(cmd,'utf-8')
        self.con.write(buf)
        print(buf)

        self.con.write(bytes('r\n','utf-8'))
        time.sleep(1)
        try:
            con_str = self.con.readline()
            print(con_str)
            data = json.loads(con_str.decode('utf-8'))
            print(data)
        except ValueError:
            messagebox.showerror('ArdClk','Error!')
            print("ValueError")

        else:
            date_time = '{}'.format(data['TIME']['DATETIME'])
            d = datetime.datetime.strptime(date_time,'%Y/%m/%d/%H:%M:%S')
            self.date_time.set(d.strftime('%Y-%m-%d(%a)%H:%M:%S'))

    #アラーム設定「設定」ボタン処理
    def wsubmit(self):
        try:
            hh = self.alm_hh_spin.get()
            mm = self.alm_mm_spin.get()
            time_str='{}:{}'.format(hh,mm)
            print(time_str)
            datetime.datetime.strptime(time_str,'%H:%M')

        except ValueError:
            messagebox.showerror('ArdClk','Error!')
            print("Alarm Value Error!")
            return

        cmd = "w,{},{}\n".format(hh,mm)
        buf = bytes(cmd, 'utf-8')
        self.con.write(buf)
        print(buf)


    #タイマー設定「設定」ボタン処理
    def tsubmit(self):
        try:
            mm = self.tm_mm_spin.get()
            ss = self.tm_ss_spin.get()
            time_str = "{}:{}".format(mm,ss)
            datetime.datetime.strptime(time_str,'%M:%S')

        except ValueError:
            messagebox.showerror('ArdClk','Error!')
            print('Timer Error')
            return

        cmd = "t,{},{}\n".format(mm,ss)
        buf = bytes(cmd, 'utf-8')
        self.con.write(buf)
        print(buf)

    def m_submit(self):
        cmd = 'm,' + self.msgEditBox.get() +'\n'
        buf = bytes(cmd,'utf-8')
        self.con.write(buf)

    def dht_submit(self):

        self.con.write(bytes('r\n','utf-8'))
        time.sleep(1)
        try:
            con_str = self.con.readline()
            data = json.loads(con_str.decode('utf-8'))
            print(data)
        except ValueError:
            messagebox.showerror('ArdClk','Error!')
            print("ValueError")

        else:
            rh_tmp = '湿度:{:.0f}% 温度:{:.0f}℃'.format(float(data['ENV']['RH']),float(data['ENV']['TEMP']))
            self.dht_val.set(rh_tmp)

    def mailcheck(self):
        mail = imaplib.IMAP4_SSL( SERVER_NAME )
        mail.login( USERNAME, PASSWORD )
#        mail.list()
        mail.select( "Inbox" )
#        ( st, mlist ) = mail.status( 'Inbox', "(UNSEEN)" )
        ( st, b_mlist ) = mail.search( None, "(UNSEEN)" )
        if ( st == "OK" ):
#            mcount = int( mlist[0].split()[2].decode().strip(').,]') )
            mlist = b_mlist[0].decode().split()
            mcount = len(mlist)

            if mcount  > 0 :
                msg = "m,You got " + str(mcount) + "Mail." + '\n'
                buf = bytes(msg, 'utf-8')
                self.con.write(buf)
                print("You got " + str(mcount) + "Mail.")
            else:
                print("No new mail.")
        else:
            print( "Can't get Mail status." )

        mail.close()
        mail.logout()

    def update_mail(self):
        self.mailcheck()
        self.master.after(60000, self.update_mail)

if __name__ == '__main__':
    root = tk.Tk()
    root.wm_title('ArdClock')
    app = App(master=root)
    root.geometry("400x300+730+360")
    root.mainloop()
