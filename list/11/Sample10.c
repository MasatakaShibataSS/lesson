#include <stdio.h>

/* 構造体型struct Carの宣言 */
typedef struct Car{
  int num;
  double gas;
}Car;

int main(void)
{
  // Car cars[3];
  Car cars[3] = {{123,10.5},{456,20.5},{789,30.5}};


  int i;
/*
  cars[0].num = 1234; cars[0].gas =25.5;
  cars[1].num = 4567; cars[1].gas =35.5;
  cars[2].num = 6789; cars[2].gas =45.5;
*/
  for(i=0; i<3; i++)
{
  printf("車のナンバーは%dです。ガソリン量は%lfです。\n", cars[i].num, cars[i].gas);
}


   return 0;
}
