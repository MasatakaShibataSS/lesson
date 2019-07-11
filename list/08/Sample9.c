#include <stdio.h>
#define MAX(x, y) (x > y ? x :y)

int main(void)
{
  int num1, num2, ans;
  double dans;

  printf("1番目の整数を入力してください。\n");
  scanf("%d", &num1);

  printf("2番目の整数を入力してください。\n");
  scanf("%d", &num2);

  ans = MAX(num1, num2);
  printf("最大値は%dです\n", ans);

  dans = MAX(10.5, 9.5);
  printf("最大値は%fです\n", dans);

   return 0;
}
