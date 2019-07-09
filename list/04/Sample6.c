#include <stdio.h>

int main(void)
{
//  int sum = 0;
  int sum;
  int num = 0;

  printf("整数１を入力してください。\n");
  scanf("%d", &num);
  sum += num;

  printf("整数2を入力してください。\n");
  scanf("%d", &num);
  sum += num;

  printf("整数3を入力してください。\n");
  scanf("%d", &num);
  sum += num;

  printf("3つの数の合計は%dです。\n", sum);

  return 0;
}
