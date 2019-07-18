#include <stdio.h>
int x=10;

void f()

{
  // static char y=("a");
  static int y=66;

  printf("変数yの値は%dです。\n", y);
  printf("変数yのアドレスは%pです。\n", &y);

}
void fa()

{
  // static char y=("a");
  int xy=777;

  printf("変数xyの値は%dです。\n", xy);
  printf("変数xyのアドレスは%pです。\n", &xy);

}
void fb()

{
  // static char y=("a");
  int yy=666;

  printf("変数yyの値は%dです。\n", yy);
  printf("変数yyのアドレスは%pです。\n", &yy);

}



int main(void)
{
  int a = 5;
  // char *pA;
  int *pA;
  pA=&x+1;
  // int b = 10;
  // int c = 30;

  printf("変数aの値は%dです。\n", a);
  printf("変数aのアドレスは%pです。\n", &a);

  printf("変数xの値は%dです。\n", x);
  printf("変数xのアドレスは%pです。\n", &x);

  printf("ポインタ使用。変数yの値は%dです。\n", *pA);
  printf("ポインタ使用。変数yのアドレスは%pです。\n", pA);

 f();
 fa();
 fb();

   return 0;
}
