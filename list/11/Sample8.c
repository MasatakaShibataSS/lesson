#include <stdio.h>

/* 構造体型struct Carの宣言 */
typedef struct Car{
  int num;
  double gas;
}Car;


/* show関数の宣言 */
void show(Car c);

int main(void)
{
  Car car1 = {0, 0.0};

  printf("ナンバーを入力してください。\n");
  scanf("%d",  &car1.num);


  printf("ガソリン量を入力してください。\n");
  scanf("%lf", &car1.gas);

  show(car1);

  printf("main車のナンバーは%d：ガソリン量は%fです。\n", car1.num, car1.gas);


   return 0;
}

/* show関数の定義 */
void show(Car c)
{
    printf("車のナンバーは%d：ガソリン量は%fです。\n", c.num, c.gas);

    c.num = 6666;
    c.gas = 99.99;

    printf("車のナンバーは%d：ガソリン量は%fです。\n", c.num, c.gas);

}
