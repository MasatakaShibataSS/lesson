#include <stdio.h>

/* square関数の宣言 */
int sq(int x);

int main(void)
{
  int num1, ans;
  printf("整数を入力してください。m(_ _)m\n");
  scanf("%d", &num1);

  ans = sq(num1);

  printf("%dの二乗は%dです。\n",num1, ans);


   return 0;
}

/* square関数の定義 */
int sq(int x)
{
  int ans;
  ans = x*x;
  return ans;
}
