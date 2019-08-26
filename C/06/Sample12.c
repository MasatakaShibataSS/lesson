#include <stdio.h>

int main(void)
{
  int res;
  int i;

  printf("何番目の処理を飛ばしますか？（１〜１０）\n");
  scanf("%d", &res);
//comment
  for (i=1; i<=10; i++) {
    if(i == res)
      continue;
    printf("%d番目の処理です。\n", i);
  }

   return 0;
}
