#include <stdio.h>

int main(void)
{
  int res;
  printf("整数を入力してください。\n");
  scanf("%d", &res);
  if((res % 2) == 0)
    printf("%dは偶数です。\n", res);
  else
    printf("%dは奇数です。\n", res);

   return 0;
}
