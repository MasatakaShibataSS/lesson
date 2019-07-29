#include <stdio.h>
#define MAX(x, y) (x > y ? x :y)

int main(void)
{
  int num1, num2, num3, num4, ans;
  double dans;

  printf("1番目の整数を入力してください。\n");
  scanf("%d", &num1);

  printf("2番目の整数を入力してください。\n");
  scanf("%d", &num2);

  printf("3番目の整数を入力してください。\n");
  scanf("%d", &num3);

  printf("4番目の整数を入力してください。\n");
  scanf("%d", &num4);

  ans = MAX(num1, MAX(num2, MAX(num3, num4)));
  printf("最大値は%dです\n", ans);

  dans = MAX(10.5, 9.5);
  printf("最大値は%fです\n", dans);

   return 0;
}
