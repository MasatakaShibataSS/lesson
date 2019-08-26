#include <stdio.h>
#define sq(x) (x*x)

int main(void)
{
  int num1, ans;
  printf("整数を入力してください。m(_ _)m\n");
  scanf("%d", &num1);

  ans = sq(num1);

  printf("%dの二乗は%dです。\n",num1, ans);
   return 0;
}
