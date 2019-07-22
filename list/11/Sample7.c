#include<stdio.h>

/* 構造体型struct Car1の宣言 */
typedef struct Car1{
  int num;
  double gas;
  unsigned int tire : 3;
  unsigned int roof : 1;
  unsigned int color : 4;

}Car1;

/* 構造体型struct Car2の宣言 */
typedef struct Car2{
  int num;
  double gas;
  unsigned int tire;
  unsigned int roof;
  unsigned int color;
}Car2;

int main(void)
{
  printf("ビットフィールドを使った構造体のサイズは%ldバイトです。\n", sizeof(Car1));
  printf("ビットフィールドを使わない構造体のサイズは%ldバイトです。\n", sizeof(Car2));


   return 0;
}
