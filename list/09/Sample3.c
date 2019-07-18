#include <stdio.h>

int main(void)
{
  int a;
  long b=100;
  int *pA;

  a = 5;
  pA = (int *)&b;

  printf("変数aの値は%dです。\n", a);
  printf("変数aのアドレスは%pです。\n", &a);
  printf("ポインタpaの値は%pです。\n", pA);
  printf("*pAの値は%dです。\n", *pA);

   return 0;
}
