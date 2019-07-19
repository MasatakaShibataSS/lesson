#include <stdio.h>

/*関数の宣言*/
void show0(void);
void show1(void);
void show2(void);

int main(void)
{
  void (*pM[3])(void);
  int num;

  pM[0] = show0;
  pM[1] = show1;
  pM[2] = show2;

  printf("どの乗り物を呼び出しますか？（０：車　１：レーシングカー　２：飛行機）\n");
  scanf("%d", &num);

  if (0<= num && num <= 2)
    (*pM[num])();

  return 0;
}

/* 関数の定義 */
void show0(void)
{
	printf("車です。\n");
}
void show1(void)
{
  printf("レーシングカーです。\n");

}
void show2(void)
{
  printf("飛行機です。\n");

}
