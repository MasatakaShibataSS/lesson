#include <stdio.h>

int main(void)
{
  char res;
  printf("成績を入力してください。\n");
  scanf("%c", &res);

  switch (res) {
    case '':
      printf("海外旅行に行く。\n");
      break;
    case 'B':
      printf("国内旅行に行く。\n");
      break;
    default:
      printf("もう一度勉強する\n");
      break;
  }

   return 0;
}
