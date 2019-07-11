#include <stdio.h>

int a = 100;

void func(void)
{
  int b;
  static int c = 10;
  // static int c;

  printf("変数aは%d変数bは%d変数cは%dです。\n", a, b, c);
  a++;
  b++;
  c++;
}
void func2(void)
{
  int x=20;
  printf("%d\n", x);
}
int main(void)
{
  int i;

  for(i=0; i<5; i++){
  func();
  func2();
}
  return 0;
}
