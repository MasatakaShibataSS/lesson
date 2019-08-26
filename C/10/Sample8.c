#include <stdio.h>
int x;
int main(void)
{
  char *str = "Hello";

  printf("str= %p\n", str);

  printf("文字列は%sです。\n", str);

  str = "goodby";
  printf("str= %p\n", str);
  printf("文字列は%sです。\n", str);

  // char str[] = "Hello";

  // printf("文字列は%sです。\n", str);

  // str = "goodby";

  // printf("文字列は%sです。\n", str);

   return 0;
}
