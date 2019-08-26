#include <stdio.h>

/* buy関数の定義 */
void buy(int x)
{
  printf("%d万円の車をかいました。\n", x);
}
/* buy関数の呼び出し */
int main(void)
{
  int num;
  printf("1台目はいくらの車を買いますか？\n");
  scanf("%d", &num);
  buy(num);

  printf("2台目はいくらの車を買いますか？\n");
  scanf("%d", &num);
  buy(num);

  return 0;
}
