#include <stdio.h>

int main(void)
{
  int a, b, c;

  a = 5;
  b = 10;
  c = 30;

  printf("変数aの値は%dです。\n", a);
  printf("変数aのアドレスは%pです。\n", &a);

  printf("変数bの値は%dです。\n", b);
  printf("変数bのアドレスは%pです。\n", &b);

  printf("変数cの値は%dです。\n", c);
  printf("変数cのアドレスは%pです。\n", &c);

   return 0;
}
