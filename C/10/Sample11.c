#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[100];

  printf("文字列（英数字）を入力してください。\n");

  scanf("%s", str);

  printf("文字列の長さは%ldです。\n", strlen(str));

   return 0;
}
