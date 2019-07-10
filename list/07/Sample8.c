#include <stdio.h>

int main(void)
{

 char str[100];

 printf("文字列を入力してください。\n");

 //scanf("%s", str);
 scanf("%s", &str[1]);

 printf("入力した文字列は%sです。\n", &str[1]);

  return 0;
}
