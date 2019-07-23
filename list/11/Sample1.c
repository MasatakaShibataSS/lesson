#include <stdio.h>

/* 構造体型struct Carの宣言 */
struct Car{
  int num;
  double gas;
}car1, car2;

int main(void)
{
  // struct Car car1, car2;

  car1.num = 1234;
  car1.gas = 25.5;
  car2.num = 4321;
  car2.gas = 65.5;


  printf("車1のナンバーは%d：ガソリン量は%fです。\n", car1.num, car1.gas);
  printf("車2のナンバーは%d：ガソリン量は%fです。\n", car2.num, car2.gas);

   return 0;
 }
