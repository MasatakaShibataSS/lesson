#ifndef ACM1602_h
#define ACM1602_h
#include "Arduino.h"
#include <Wire.h>

// �N���X�̒�`
// �N���X���E�R���X�g���N�^���E�֐�����g�p����ϐ������`���܂��B
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
