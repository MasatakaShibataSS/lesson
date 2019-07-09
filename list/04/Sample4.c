#include <stdio.h>

int main(void)
{
  int num1 = 10;
  int num2 = 5;

  printf("num1とnum2にいろいろな演算を行います。\n");
  printf("num1+num2は%dです。\n", num1 + num2);
  printf("num1-num2は%dです。\n", num1 - num2);
  printf("num1*num2は%dです。\n", num1 * num2);
  printf("num1/num2は%dです。\n", num1 / num2);
  printf("num1%%num2は%dです。\n", num1 % num2);

  return 0;
}
