#include <stdio.h>
#include "myfunc.h"
int main(void)
{
int num1, num2, ans;

printf("1番目の整数を入力してください。m(_ _)m\n");
scanf("%d", &num1);

printf("2番目の整数を入力してください。m(_ _)m\n");
scanf("%d", &num2);

ans = power(num1, num2);
printf("%dの%d乗は%dです。\n",num1, num2, ans);
   return 0;
}
