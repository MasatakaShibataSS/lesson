#include <stdio.h>

int main(void)
{
  int num = 0;
  int sum = 0;

  printf("テストの点を入力してくだいさい。（０で終了）\n");
  do{
    scanf("%d", &num);
    sum += num;
  }while(num);
  printf("テストの合計点は%d点です。\n", sum);

   return 0;
}
