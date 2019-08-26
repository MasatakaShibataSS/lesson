#include <stdio.h>

int main(void)
{
  int i;
  double d;
  char str[100];

  printf("整数を入力してください。\n");
  scanf("%d", &i);

  printf("小数値を入力してください。\n");
  scanf("%lf", &d);

  printf("文字列を入力してください。\n");
  scanf("%s", str);

  printf("入力された整数は%dです。\n", i);
  printf("入力された小数値は%fです。\n", d);
  printf("入力された文字列は%sです。\n", str);

   return 0;
}
