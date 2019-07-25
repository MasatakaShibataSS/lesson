#include <stdio.h>

int main(void)
{
  int num1;

  printf("0から10までの整数を入力してください。\n");
  scanf("%d", &num1);


  if (num1 >= 0 && num1 <= 10) {
    printf("正解です。\n");
  }

  else{
    printf("間違いです。\n");

  }
   return 0;
}
