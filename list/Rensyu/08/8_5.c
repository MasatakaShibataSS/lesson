#include <stdio.h>
// #include "myfunc.h"
#include <math.h>
int main(void)
{
// int num1, num2, ans;
double num1, num2, ans;

printf("1番目の整数を入力してください。m(_ _)m\n");
// scanf("%d", &num1);
scanf("%lf", &num1);

printf("2番目の整数を入力してください。m(_ _)m\n");
// scanf("%d", &num2);
scanf("%lf", &num2);

// ans = power(num1, num2);
ans = pow(num1, num2);

printf("%.2fの%.2f乗は%.2fです。\n",num1, num2, ans);
   return 0;
}
