#include <stdio.h>

/* buy関数の定義 */
void buy(int x, int y)
{
  printf("%d万円と%d万円の車を買いました。\n", x, y);

}
/* buy関数の呼び出し */
int main(void)
{
  int num1, num2;
  printf("1台目はいくらの車を買いますか？\n");
  scanf("%d", &num1);

  printf("2台目はいくらの車を買いますか？\n");
  scanf("%d", &num2);

  buy(num1,num2);
  // buy(num2,num1);

   return 0;
}
