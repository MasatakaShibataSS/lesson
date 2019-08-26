//==================================================================
// File Name    : RTC8564.cpp
//
// Title        : RTC8564ライブラリ・ソース
// Revision     : 1.1
// Notes        : 
//
// This code is distributed under the GNU Public License
//		which can be found at http://www.gnu.org/licenses/gpl.txt
//

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#include <Wire.h>
#include "RTC8564.h"

#if ARDUINO < 100
#define SEND(x) send(x)
#define RECEIVE(x) receive(x)
#else
#define SEND(x) write(static_cast<uint8_t>(x))
#define RECEIVE(x) read(x)
#endif

// Constructors ////////////////////////////////////////////////////////////////
RTC8564::RTC8564()
{
}

// Destructor //////////////////////////////////////////////////////////////////
RTC8564::~RTC8564()
{
}

//========================================================================
//  曜日判定
//------------------------------------------------------------------------
// 引数: int nYear  : 年
//       int nMonth : 月
//       int nDay   : 日
// 戻値: 0:日, ... 6:土
//========================================================================
int RTC8564::getWeekday( int nYear, int nMonth, int nDay )
{
    int nWeekday, nTmp;

    if (nMonth == 1 || nMonth == 2)
    {
        nYear--;
        nMonth += 12;
    }

    nTmp = nYear/100;
    nWeekday = (nYear + (nYear >> 2) - nTmp + (nTmp >> 2) + (13 * nMonth + 8)/5 + nDay) % 7;

    return nWeekday;
}

//========================================================================
//  convert bin to BCD
//------------------------------------------------------------------------
// 引数:
// 戻値:
//========================================================================
uint8_t RTC8564::dec2bcd( uint8_t d )
{
    return ((d/10 * 16) + (d % 10));
}

//========================================================================
//  convert BCD to bin
//------------------------------------------------------------------------
// 引数:
// 戻値:
//========================================================================
uint8_t RTC8564::bcd2dec( uint8_t b )
{
    return ((b/16 * 10) + (b % 16));
}

void RTC8564::power_on( )
{
    delay(1000);
    init();
}

void RTC8564::init( )
{
    beginTransmission(RTC8564_SLAVE_ADRS);
    SEND(0x00);         // write reg addr 00
    SEND(0x20);         // 00 Control 1, STOP=1
    SEND(0x00);         // 01 Control 2
    SEND(0x00);         // 02 Seconds
    SEND(0x00);         // 03 Minutes
    SEND(0x00);         // 04 Hours
    SEND(0x01);         // 05 Days
    SEND(0x01);         // 06 Weekdays
    SEND(0x01);         // 07 Months
    SEND(0x01);         // 08 Years
    SEND(0x80);         // 09 Minutes Alarm
    SEND(0x80);         // 0A Hours Alarm
    SEND(0x80);         // 0B Days Alarm
    SEND(0x80);         // 0C Weekdays Alarm
    SEND(0x00);         // 0D CLKOUT
    SEND(0x00);         // 0E Timer control
    SEND(0x00);         // 0F Timer
    SEND(0x00);         // 00 Control 1, STOP=0(START)
    endTransmission();
}

bool RTC8564::readReg( uint8_t mem_addr, uint8_t *data )
{
    beginTransmission(RTC8564_SLAVE_ADRS);
    SEND(mem_addr);
    endTransmission();

    requestFrom(RTC8564_SLAVE_ADRS, 1);         // Request 1 bytes
    if (available())
    {
        *data = RECEIVE();
        return true;
    }
    return false;
}

void RTC8564::writeReg( uint8_t mem_addr, uint8_t data )
{
    beginTransmission(RTC8564_SLAVE_ADRS);
    SEND(mem_addr);
    SEND(data);
    endTransmission();
}


bool RTC8564::setRegBit(uint8_t mem_addr, uint8_t set_bit )
{
    uint8_t data;

    if(readReg(mem_addr, &data))
    {
        data |= set_bit;
        writeReg( mem_addr, data );
        return true;
    }
    return false;
}

bool RTC8564::clearRegBit(uint8_t mem_addr, uint8_t clear_bit )
{
    uint8_t data;

    if (readReg(mem_addr, &data))
    {
        data &= ~clear_bit;
        writeReg( mem_addr, data );
        return true;
    }
    return false;
}


bool RTC8564::masksetRegBit( uint8_t mem_addr, uint8_t mask, uint8_t set_bit )
{
    uint8_t data;

    if( readReg(mem_addr, &data) )
    {
        data &= ~mask;
        data |= set_bit;
        writeReg( mem_addr, data );
        return true;
    }
    return false;
}

void RTC8564::begin()
{
    TwoWire::begin();

    if (!isRunning())
    {
        power_on();
    }
}

bool RTC8564::isRunning()
{
    uint8_t data;

    if (readReg( 0x02, &data ))         // Seconds レジスタ
    {
        return !(data & _BV(7));
    }
    return false;
}


//========================================================================
// 時計・カレンダの設定(アプリケーションマニュアル P-30)
//------------------------------------------------------------------------
// 引数: RTC_TIME *time: 設定する日時データ
// 戻値: なし
//========================================================================
void RTC8564::adjust(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
{
    // RTC8564 stop
    masksetRegBit( 0x00, _BV(7) | _BV(5) | _BV(3), _BV(5) );

    beginTransmission(RTC8564_SLAVE_ADRS);
    SEND(0x02);             // Seconds レジスタ
    SEND(dec2bcd(sec));		// sec
    SEND(dec2bcd(min));   	// min
    SEND(dec2bcd(hour));  	// hour
    SEND(dec2bcd(day));   	// day
    SEND((uint8_t)getWeekday( year, month, day ));    // week of day

    if ( year >= 2100)    	// month & year
    {
        SEND(dec2bcd(month) | 0x80);
        SEND(dec2bcd(year - 2100));
    }
    else
    {
        SEND(dec2bcd(month));
        SEND(dec2bcd(year - 2000));
    }
    endTransmission();

    // RTC8564 start
    clearRegBit( 0x00, _BV(7) | _BV(5) | _BV(3) );
}

void RTC8564::adjust(RTC_TIME time)
{
	adjust(time.year, time.month, time.day, time.hour, time.min, time.sec);
}

//========================================================================
// 時計・カレンダの読み出し(アプリケーションマニュアル P-30)
//------------------------------------------------------------------------
// 引数: RTC_TIME *time: 取得する日時のデータ
// 戻値: true 取得成功, false 取得失敗
//========================================================================
bool RTC8564::now(RTC_TIME *time)
{
    uint8_t tmp;

    beginTransmission(RTC8564_SLAVE_ADRS);
    SEND(0x02);                                 // Seconds レジスタ
    endTransmission();

    requestFrom(RTC8564_SLAVE_ADRS, 7);         // Request 7 bytes
    if (available())
    {
        time->sec= bcd2dec(RECEIVE() & 0x7F);   // 秒
        time->min= bcd2dec(RECEIVE() & 0x7F);   // 分
        time->hour = bcd2dec(RECEIVE() & 0x3F); // 時
        time->day = bcd2dec(RECEIVE() & 0x3F);  // 日
        time->wday = bcd2dec(RECEIVE() & 0x07); // 曜日
        tmp = RECEIVE();
        time->month = bcd2dec(tmp & 0x1F);
        time->year = bcd2dec(RECEIVE());
        if (tmp & 0x80)
        {
            time->year += 2100;
        }
        else
        {
            time->year += 2000;
        }
        return true;
    }

    return false;
}

//========================================================================
//  タイマー設定・開始
//------------------------------------------------------------------------
// 引数:    RTC_TIMER_TIMING sclk　: タイマ周波数
//          uint8_t count   : タイマカウント
//          bool cycle      : trueなら繰り返し
//          boolint_out     : trueなら /INT "LOW"レベル割り込み出力許可
// 戻値: なし
//========================================================================
void RTC8564::setTimer( RTC_TIMER_TIMING sclk, uint8_t count,bool cycle = false, bool int_out = true )
{
    uint8_t data[2];
    uint8_t status;

    // タイマ割り込み停止(TE = 0)
    clearRegBit( 0x0E, _BV(7) );

    // 割り込み解除およびフラッグクリア( TIE=0, TF=0 )
    clearRegBit( 0x01, _BV(2) | _BV(0) );

    if ( cycle )
    {
        // 繰り返し割り込み( TI/TP = 1 )
        setRegBit( 0x01, _BV(4) );
    }
    else
    {
        // 一度きりの割り込み( TI/TP = 0 )
        clearRegBit( 0x01, _BV(4) );
    }

    if ( int_out )
    {
        // /INT "LOW"レベル割り込み出力許可( TIE = 1 )
        setRegBit( 0x01, _BV(0) );
    }
    else
    {
        // /INT "LOW"レベル割り込み出力不許可( TIE = 0 )
        clearRegBit( 0x01, _BV(0) );
    }

    // タイマカウントダウン周期設定
    masksetRegBit( 0x0E, _BV(1) | _BV(0), sclk );

    // タイマカウンタ値設定
    writeReg( 0x0F, count );

    setRegBit( 0x0E, _BV(7) );    // タイマ割り込み許可(TE = 1)
}

void RTC8564::stopTimer()
{
    // タイマ割り込み停止(TE = 0)
    clearRegBit( 0x0E, _BV(7) );

    // 割り込み解除およびフラッグクリア( TIE=0, TF=0 )
    clearRegBit( 0x01, _BV(2) | _BV(0) );
}

void RTC8564::clearTimer()
{
	clearRegBit(0x01, _BV(2) );		// 2013/5/6 修正
}

bool RTC8564::checkTimerFlag()
{
    uint8_t data;

    if ( readReg( 0x01, &data ) )
    {
        if( data & _BV(2) )
        {
            return true;
        }
    }
    return false;
}

//========================================================================
//  アラーム設定・開始
//------------------------------------------------------------------------
// 引数: ALARM_TIME *alarm : アラームの設定データ
// 戻値: なし
//========================================================================
void RTC8564::setAlarm( ALARM_TIME alarm, bool int_out = true )
{
    uint8_t data[4];

    // 割り込み解除( AIE=0, AF=0 )
    clearRegBit( 0x01, _BV(3) | _BV(1) );

    // アラーム割り込み全停止(AE = 1)
    beginTransmission(RTC8564_SLAVE_ADRS);
    SEND(0x09);                 // Minute Alarmレジスタ・アドレス
    SEND(0x80);                 // Minute Alarm (AE=1)
    SEND(0x80);                 // Hour Alarm (AE=1)
    SEND(0x80);                 // Day Alarm (AE=1)
    SEND(0x80);                 // Week Day Alarm (AE=1)
    endTransmission();

    if ( int_out )
    {
        // /INT "LOW"レベル割り込み出力許可( AIE = 1 )
        setRegBit( 0x01, _BV(1) );
    }
    else
    {
        // /INT "LOW"レベル割り込み出力不許可( AIE = 0 )
        clearRegBit( 0x01, _BV(1) );
    }

    // 毎分設定
    data[0] = dec2bcd(alarm.min & 0x7F);
    if(alarm.min & 0x80)
    {
        data[0] |= 0x80;
    }

    // 毎時設定
    data[1] = dec2bcd(alarm.hour & 0x7F);
    if(alarm.hour & 0x80)
    {
        data[1] |= 0x80;
    }

    // 毎日設定
    data[2] = dec2bcd(alarm.day & 0x7F);
    if(alarm.day & 0x80)
    {
        data[2] |= 0x80;
    }

    // 毎曜日設定
    data[3] = dec2bcd(alarm.wday & 0x7F);
    if(alarm.wday & 0x80)
    {
        data[3] |= 0x80;
    }

    // アラーム割り込み設定
    beginTransmission(RTC8564_SLAVE_ADRS);
    SEND(0x09);                 // Minute Alarmレジスタ・アドレス
    SEND(data[0]);              // Minute Alarm
    SEND(data[1]);              // Hour Alarm
    SEND(data[2]);              // Day Alarm
    SEND(data[3]);              // Week Day Alarm
    endTransmission();

    // 割り込み許可(AIE=1)
    setRegBit( 0x01, _BV(1) );
}

void RTC8564::stopAlarm()
{
    // 割り込み解除( AIE=0, AF=0 )
    clearRegBit( 0x01, _BV(3) | _BV(1) );

    // アラーム割り込み全停止(AE = 1)
    beginTransmission(RTC8564_SLAVE_ADRS);
    SEND(0x09);                 // Minute Alarmレジスタ・アドレス
    SEND(0x80);                 // Minute Alarm (AE=1)
    SEND(0x80);                 // Hour Alarm (AE=1)
    SEND(0x80);                 // Day Alarm (AE=1)
    SEND(0x80);                 // Week Day Alarm (AE=1)
    endTransmission();
}

void RTC8564::clearAlarm()
{
	clearRegBit(0x01, _BV(3) );
}

bool RTC8564::checkAlarmFlag()
{
    uint8_t data;

    if ( readReg( 0x01, &data ) )
    {
        if( data & _BV(3) )     // AFフラッグをチェック
        {
            return true;
        }
    }
    return false;
}


void RTC8564::setClkOut( RTC_CLKOUT_FREQ clkout )
{
    if( clkout == FREQ_0 )
    {
        clearRegBit( 0x0D, _BV(7) );
    }
    else
    {
        masksetRegBit( 0x0D, _BV(7) | _BV(1) | _BV(0), _BV(7) | clkout );
    }
}

//RTC8564
