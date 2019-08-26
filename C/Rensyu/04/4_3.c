#include <stdio.h>

int main(void)
{
  double a,b;
  printf("三角形の高さを入力してください\n");
  scanf("%lf", &a);

  printf("三角形の底辺を入力してください\n");
  scanf("%lf", &b);
//1aaaa
  printf("三角形の面積は%fです。\n", a * b / 2);
   return 0;
}
