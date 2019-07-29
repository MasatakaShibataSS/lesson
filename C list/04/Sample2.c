#include <stdio.h>

int main(void)
{
  int num1 = 2;
  int num2 = 3;
  int sum = num1+num2;

  printf("変数num1の値は%dです。\n", num1);
  printf("変数num2の値は%dです。\n", num2);
  printf("num1+num2の値は%dです。\n", sum);

  num1 = num1+1;

  printf("変数num1の値に1をたすと%dです。\n", num1);


   return 0;
}
