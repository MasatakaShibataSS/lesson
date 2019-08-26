#include <stdio.h>

int main(void)
{
  int res;

  printf("成績を入力してください。\n");
  scanf("%d", &res);

  printf("成績は%dです。\n", res);

  switch (res) {
    case 1:
      printf("もっとがんばりましょう。\n");
      break;
    case 2:
      printf("もう少しがんばりましょう。\n");
      break;
    case 3:
      printf("さらに上を目指しましょう。\n");
      break;
    case 4:
      printf("たいへんよくできました。\n");
      break;
    case 5:
      printf("たいへん優秀です。\n");
      break;

  }
   return 0;
}
