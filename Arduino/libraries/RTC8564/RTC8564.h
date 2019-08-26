//==================================================================
// File Name    : RTC8564.h
//
// Title        : RTC8564ライブラリ・ヘッダ
// Revision     : 1.1
// Notes        : 
//
// This code is distributed under the GNU Public License
//		which can be found at http://www.gnu.org/licenses/gpl.txt
//

#ifndef __RTC8564_H__
#define __RTC8564_H__

#include <inttypes.h>
#include <Wire.h>

#define RTC8564_SLAVE_ADRS 0x51

typedef struct
{
    uint8_t sec;        // 0 to 59
    uint8_t min;        // 0 to 59
    uint8_t hour;       // 0 to 23
    uint8_t day;        // 1 to 31
    uint8_t month;      // 1 to 12
    uint16_t year;      // 2000 to
    uint8_t wday;       // 0 to 6
} RTC_TIME;

typedef struct
{
    uint8_t min;        // 0 to 59
    uint8_t hour;       // 0 to 23
    uint8_t day;        // 1 to 31
    uint8_t wday;       // 0 to 6
} ALARM_TIME;

class RTC8564 : public TwoWire
{
public:
    enum RTC_CLKOUT_FREQ { FREQ_32768=0, FREQ_1024=1, FREQ_32=2, FREQ_1=3, FREQ_0=4 };
    enum RTC_TIMER_TIMING { TIMING_244_14_MS=0, TIMING_15_625_MS=1, TIMING_1_SEC=2, TIMING_1_MIN=3 };

    RTC8564();
    ~RTC8564();     // destructor

    void begin();
    void adjust(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);
    void adjust(RTC_TIME time);
    bool now(RTC_TIME *time);
    bool isRunning();
    void setClkOut( RTC_CLKOUT_FREQ clkout );
    void setTimer( RTC_TIMER_TIMING sclk, uint8_t count,bool cycle, bool int_out);
    void stopTimer();
    void clearTimer();
	bool checkTimerFlag();
    void setAlarm( ALARM_TIME alarm, bool int_out );
    void stopAlarm();
    void clearAlarm();
	bool checkAlarmFlag();
protected:
    int getWeekday( int nYear, int nMonth, int nDay );
    uint8_t dec2bcd(uint8_t d);
    uint8_t bcd2dec(uint8_t b);
    void init();
    void power_on();
    bool readReg( uint8_t mem_addr, uint8_t *data );
    void writeReg( uint8_t mem_addr, uint8_t data );
    bool setRegBit(uint8_t mem_addr, uint8_t set_bit );
    bool clearRegBit(uint8_t mem_addr, uint8_t clear_bit );
    bool masksetRegBit( uint8_t mem_addr, uint8_t mask, uint8_t set_bit );
};

#endif
