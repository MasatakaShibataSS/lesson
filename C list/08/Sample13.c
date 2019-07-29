#include <stdio.h>
#include "myfunc.h"

int main(void)
{
  int num1, num2, ans;

  printf("1番目の整数を入力してください。\n");
  scanf("%d", &num1);

  printf("2番目の整数を入力してください。\n");
  scanf("%d", &num2);

  ans = max(num1, num2);

  printf("最大値は%d\n", ans);



   return 0;
}
