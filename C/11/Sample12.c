#include <stdio.h>

/* 共用体型union Yearの宣言 */
typedef union Year{
  int ad;
  // int gengo;
  char gengo;

}Year;

int main(void)
{
  Year myyear;
  int a, g;

  printf("西暦を入力してください。\n");
  scanf("%d", &a);

  myyear.ad = a;

  printf("西暦は%dです。\n", myyear.ad);
  printf("元号は%dです。\n", myyear.gengo);

  printf("元号を入力してください。\n");
  scanf("%d", &g);

  myyear.gengo = g;


  printf("西暦は%dです。\n", myyear.ad);
  printf("元号は%dです。\n", myyear.gengo);


   return 0;
}
