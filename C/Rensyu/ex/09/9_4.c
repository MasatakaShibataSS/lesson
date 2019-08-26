#include <stdio.h>

/* add関数の宣言 */


void add(int x, int y, int a)
{
  x += a;
  y += a;

}
int main(void)
{
  int num1 = 0;
  int num2 = 0;
  int a =0;
  printf("2科目分の点数を入力してください。\n");
  scanf("%d", &num1);
  scanf("%d", &num2);

  printf("加点する点数を入力してください。\n");
  scanf("%d", &a);

  add(num1, num2, a);
  printf("%d点加点しました。\n", a);
  printf("科目1は%d点となりました。\n", num1);
  printf("科目2は%d点となりました。\n", num2);

   return 0;
}

/* add関数の定義 */
