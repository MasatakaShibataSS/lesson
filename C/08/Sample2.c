#include <stdio.h>

/* buy関数の定義 */
void buy(void)
{
  printf("車を買いました。\n");
}

/* buy関数の呼び出し */
int main(void)
{
  buy();
  printf("もう一台車を購入します。\n");
  buy();


   return 0;
}
