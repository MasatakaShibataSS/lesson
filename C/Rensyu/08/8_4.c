#include <stdio.h>
#define SQUARE(x) (x*x)

int main(void)
{
int num1, ans;

printf("整数を入力してください。m(_ _)m\n");
scanf("%d", &num1);

ans = SQUARE(num1);

printf("%dの2乗は%dです。\n",num1, ans);

   return 0;
}
