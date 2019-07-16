#include <stdio.h>

/* square関数の宣言 */
int square(int x);

int main(void)
{
int num1, ans;

printf("整数を入力してください。m(_ _)m\n");
scanf("%d", &num1);

ans = square(num1);

printf("%dの2乗は%dです。\n",num1, ans);

   return 0;
}

/* square関数の定義 */
int square(int x)
{
  int y;
  y = x*x;
    return y;
}
