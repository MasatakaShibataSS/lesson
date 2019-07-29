#include <stdio.h>

int main(void)
{
  int num = 0;

  while(num == 0){
    printf("整数を入力してください。（0で終了）\n");
    scanf("%d", &num);
    printf("%dが入力されました。\n", num);

  }
  printf("繰り返しが終わりました。\n");
   return 0;
}
