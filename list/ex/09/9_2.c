#include <stdio.h>


int main(void)
{
  int a;
  int *pA;

  a = 5;
  pA = &a;

  printf("変数aの値は%dです。\n", a);
  printf("変数aのアドレスは%pです。\n", &a);
  printf("ポインタpaの値は%pです。\n", pA);
   return 0;
}
