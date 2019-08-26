#include <stdio.h>

/* buy関数の定義 */
int buy(int x, int y)
{
  int z;
  printf("%d万円と%d万円の車を買いました。\n", x, y);
  z = x+y;
  return z;
}
/* buy関数の呼び出し */
int main(void)
{
  int num1, num2, sum;
  printf("1台目はいくらの車を買いますか？\n");
  scanf("%d", &num1);

  printf("2台目はいくらの車を買いますか？\n");
  scanf("%d", &num2);

   sum = buy(num1,num2);
   printf("合計で%d万円です。\n", sum);
   // printf("合計で%d万円です。\n", buy(num1, num2));
   return 0;
}
