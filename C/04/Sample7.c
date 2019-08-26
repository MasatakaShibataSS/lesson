#include <stdio.h>

int main(void)
{
  int a = 1;
  int b = 0;

  printf("short int型のサイズは%dバイトです。\n",
    sizeof(short int));
    printf("int型のサイズは%dバイトです。\n",(int)sizeof(int));
    printf("long int型のサイズは%dバイトです。\n",(int)sizeof(long int));
    printf("float型のサイズは%dバイトです。\n",(int)sizeof(float));
    printf("double型のサイズは%dバイトです。\n",(int)sizeof(double));
    printf("long double型のサイズは%dバイトです。\n",(int)sizeof(long double));
    printf("変数aのサイズは%dバイトです。\n",(int)sizeof(a));
    printf("式a+bのサイズは%dバイトです。\n",(int)sizeof(a+b));



   return 0;
}
