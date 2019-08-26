#include <stdio.h>

/* 列挙型enum Weekの宣言 */
typedef enum Week{SUN, MON, TUE, WED, THU, FRI, SAT} Week;

int main(void)
{
  Week w;
  w = SUN;

  switch(w){
    case SUN: printf("日曜です\n"); break;
    case MON: printf("月曜です\n"); break;
    case TUE: printf("火曜です\n"); break;
    case WED: printf("水曜です\n"); break;
    case THU: printf("木曜です\n"); break;
    case FRI: printf("金曜です\n"); break;
    case SAT: printf("土曜です\n"); break;
    default : printf("何曜日だかわかりません\n"); break;
  }

   return 0;
}
