#include <stdio.h>

int main(void)
{
int ch;

printf("文字を続けて入力してください。\n");

while ((ch=getchar()) != EOF) {
  putchar(ch);
}
   return 0;
}
