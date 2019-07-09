#include <stdio.h>

int main(void)
{
  char res;

  printf("A〜Cまでの文字を入力してください。\n");
  res = getchar();


  if (res == 'A' || res == 'B' || res == 'C') {
    printf("正解です。\n");
  }

  else{
    printf("間違いです。\n");

  }
   return 0;
}
