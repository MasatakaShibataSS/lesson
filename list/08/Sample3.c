#include <stdio.h>

/* buy関数の定義 */
void buy(int x)
{
  printf("%d万円の車を買いました。\n", x);
}
/* buy関数の呼び出し */
int main(void)
{
//  int x=20;
  buy(20);
  buy(50);
//  printf("x=%d\n", x);


  return 0;
}
