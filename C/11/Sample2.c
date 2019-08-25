#include <stdio.h>

/* 構造体型struct Carの宣言 */
struct Car{
  int num;
  double gas;
};

int main(void)
{
  struct Car car1, car2;
printf("車1のナンバーを入力してください\n");
scanf("%d", &car1.num);
printf("車1のガソリン量を入力してください\n");
scanf("%lf", &car1.gas);

printf("車2のナンバーを入力してください\n");
scanf("%d", &car2.num);
printf("車2のガソリン量を入力してください\n");
scanf("%lf", &car2.gas);


  printf("車1のナンバーは%d：ガソリン量は%fです。\n", car1.num, car1.gas);
  printf("車2のナンバーは%d：ガソリン量は%fです。\n", car2.num, car2.gas);

   return 0;
}
