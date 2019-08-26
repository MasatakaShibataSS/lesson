#include "Arduino.h"
#include "ACM1602.h"
#include <Wire.h>

#define CMD_MODE 0x00
#define DATA_MODE 0x80

ACM1602::ACM1602(int address, int bls)
{
	I2C_ADDR = address;
	BL_SOCKET = bls;
}

void ACM1602::begin()
{
	TWBR = ((F_CPU / 100000L) - 16) / 2;

	cursol = 1;
	blink = 1;
	display = 1;
	x = 0;
	y = 0;
	
	lcd_write(CMD_MODE,0x01);
	delay(150);
	lcd_write(CMD_MODE,0x38);
	delay(100);
	lcd_write(CMD_MODE,0x0f);
	delay(100);
	lcd_write(CMD_MODE,0x06);
	delay(100);
	
	pinMode( BL_SOCKET, OUTPUT );
	digitalWrite( BL_SOCKET, LOW );
}

void ACM1602::lcd_write(int mode, int cmd)
{
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(mode);
	Wire.write(cmd);
	Wire.endTransmission();
}

void ACM1602::clear()
{
	lcd_write(CMD_MODE,0x01);
	delay(100);
}

void ACM1602::set_display()
{
	int buf;
	buf = 0x08 + 0x04 * display + 0x02 * cursol + blink;
	lcd_write(CMD_MODE,buf);
	delay(100);
}

void ACM1602::set_cursol(int flag)
{
	if ( flag != 0 ) {
		flag = 1;
	}
	cursol = flag;
	set_display();
}

void ACM1602::set_blink(int flag)
{
	if ( flag != 0 ) {
		flag = 1;
	}
	blink = flag;
	set_display();
}

void ACM1602::move(int mx, int my)
{
	int buf;
	x = mx;
	y = my;
	if ( x < 0 ){
		x = 0;
	}
	if ( x > 0x0f){
		x = 0x0f;
	}
	if ( y < 0 ){
		y = 0;
	}
	if ( y > 0x01){
		y = 0x01;
	}
	
	buf = x + ( y * 0x40 ) + 0x80;
	lcd_write(CMD_MODE,buf);
	delay(100);
}

void ACM1602::backlight(int flag)
{
	if ( flag == 0 ){
		digitalWrite( BL_SOCKET, LOW );
	}else{
		digitalWrite( BL_SOCKET, HIGH );
	}
}

void ACM1602::charwrite(char *outchar)
{
	String str;
	str = outchar;
	int i,length;
	
	length = str.length();
	for ( i = 0; i < length; i++){
		if ( x > 0x0f){
			if ( y == 0 ){
				move(0x00,0x01);
				y = 0x01;
			}else{
				break;
			}
		}
		lcd_write(DATA_MODE,str.charAt(i));
		x++;
	}

}
