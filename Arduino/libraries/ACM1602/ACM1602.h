#ifndef ACM1602_h
#define ACM1602_h
#include "Arduino.h"
#include <Wire.h>

// クラスの定義
// クラス名・コンストラクタ名・関数名や使用する変数名を定義します。
class ACM1602
{
	public:
		ACM1602(int address, int bls);
		void begin();
		void lcd_write(int mode,int cmd);
		void clear();
		void set_display();
		void set_cursol(int flag);
		void set_blink(int flag);
		void move(int mx, int my);
		void backlight(int flag);
		void charwrite(char *outchar);
	private:
		int I2C_ADDR, BL_SOCKET;
		int cursol, blink, display, x, y;
};

#endif
