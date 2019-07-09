#include <stdio.h>

int main(void)
{
  int n;
  printf("数値を入力してください。\n");
  scanf("%d", &n);
  printf("input : %d\n", n);
  printf("ASCII : %c\n", n);
  printf("大文字 : %c\n", n&0xdf);

  return 0;
}
