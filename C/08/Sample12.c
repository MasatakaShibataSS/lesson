#include <stdio.h>

/* max関数の宣言 */
int max(int x, int y);

int main(void)
{
  int num1, num2, ans;

  printf("1番目の整数を入力してください。\n");
  scanf("%d", &num1);

  printf("2番目の整数を入力してください。\n");
  scanf("%d", &num2);

  ans = max(num1, num2);

  printf("最大値は%dです。\n", ans);
   return 0;
}

/* max関数の定義 */
int max(int x, int y)
{
  if (x > y)
    return x;
  else
    return y;
}
