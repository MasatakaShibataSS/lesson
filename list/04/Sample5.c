#include <stdio.h>

int main(void)
{
  int a = 0;
  int b = 0;

  //b = a++;
  b = ++a;

  printf("代入後にインクリメントしたのでbの値は%dです\n", b);

   return 0;
}
