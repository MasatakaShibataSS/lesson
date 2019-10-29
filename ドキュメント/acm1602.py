import smbus, time
import RPi.GPIO as GPIO

class acm1602:
    def __init__(self,ch,ad,blpin):
        self.ch = ch
        self.ad = ad
        self.blpin = blpin
        self.cursol = 1
        self.blink = 1
        self.display = 1
        self.x = 0
        self.y = 0

        self.i2c = smbus.SMBus(ch)
        self.i2c.write_byte_data(self.ad, 0x00, 0x01)
        time.sleep(0.15)
        self.i2c.write_byte_data(self.ad, 0x00, 0x38)
        time.sleep(0.1)
        self.i2c.write_byte_data(self.ad, 0x00, 0x0f)
        time.sleep(0.1)
        self.i2c.write_byte_data(self.ad, 0x00, 0x06)
        time.sleep(0.1)

        GPIO.setmode(GPIO.BCM)
        GPIO.setup(self.blpin,GPIO.OUT)

    def clear(self):
        self.i2c.write_byte_data(self.ad, 0x00, 0x01)
        time.sleep(0.1)

    def set_display(self):
        buf = 0x08 + 0x04 * self.display + 0x02 * self.cursol + self.blink
        self.i2c.write_byte_data(self.ad, 0x00, buf)
        time.sleep(0.1)

    def set_cursol(self,buf):
        if buf != 0:
            buf = 1
        self.cursol = buf
        self.set_display()

    def set_blink(self,buf):
        if buf != 0:
            buf = 1
        self.blink = buf
        self.set_display()

    def move_home(self):
        self.x = 0
        self.y = 0
        self.i2c.write_byte_data(self.ad, 0x00, 0x02)
        time.sleep(0.1)

    def move(self,mx,my):
        self.x = mx
        self.y = my
        if self.x < 0:
            self.x=0
        if self.x > 0x0f:
            self.x=0x0f
        if self.y < 0:
            self.y=0
        if self.y > 1:
            self.y=1
        oy=self.y*0x40
        out=self.x+oy+0x80
        self.i2c.write_byte_data(self.ad, 0x00, out)
        time.sleep(0.1)

    def write(self,buf):
        length = len(buf)
        i = 0
        while i < length:
            if self.x > 0x0f:
                if self.y == 0:
                    self.move(0x00,0x01)
                else:
                    break
            try:
                out=int(buf[i].encode("hex_codec"),16)
            except LookupError:
                # for python3
                out=ord(buf[i])
                self.i2c.write_byte_data(self.ad,0x80,out)

            self.x = self.x + 1
            i = i + 1
    def backlight(self,buf):
        if buf != 0:
           GPIO.output(self.blpin, GPIO.HIGH)
        else:
           GPIO.output(self.blpin, GPIO.LOW)
