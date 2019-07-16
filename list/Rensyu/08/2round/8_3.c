#include <stdio.h>

/* power関数の宣言 */
int power(int x, int y);

int main(void)
{
  int num1, num2, ans;

  printf("1つ目の整数を入力してください。m(_ _)m\n");
  scanf("%d", &num1);

  printf("2つ目の整数を入力してください。m(_ _)m\n");
  scanf("%d", &num2);

  ans = power(num1, num2);

  printf("%dの%d乗は%dです。\n",num1, num2, ans);

   return 0;
}

/* power関数の定義 */
int power(int x, int y)
{
  int i;
  int p = 1;
  for (i = 0; i < y; i++) {
     p = p*x;
  }
  return p;
}
