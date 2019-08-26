#include <stdio.h>

int main(void)
{
  int h;
  double pi=3.14159, s, m;
  printf("半径を入力してください\n");

  scanf("%d", &h);
  s=(2*h*pi);
  m=(h*h*pi);
  printf("円周は%fです。\n", s);
  printf("円面積は%fです。\n", m);

   return 0;
}
