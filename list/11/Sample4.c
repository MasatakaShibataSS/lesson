#include <stdio.h>

/* 構造体型struct Carの宣言 */
typedef struct Car{
  int num;
  double gas;
}Car;

int main(void)
{
  Car car1 = {1234,23.4};
	Car car2 = {4321,63.4};


  printf("車1のナンバーは%d：ガソリン量は%fです。\n", car1.num, car1.gas);
  printf("車2のナンバーは%d：ガソリン量は%fです。\n", car2.num, car2.gas);

   return 0;
}
