#include <stdio.h>

/* add関数の宣言 */
void add(int *x1, int *x2, int a);
int main(void)
{
  int x1 = 0;
  int x2 = 0;
  int a =0;
  printf("2科目分の点数を入力してください。\n");
  scanf("%d", &x1);
  scanf("%d", &x2);

  printf("加点する点数を入力してください。\n");
  scanf("%d", &a);

  add(&x1, &x2, a);
  printf("%d点加点しました。\n", a);
  printf("科目1は%d点となりました。\n", x1);
  printf("科目2は%d点となりました。\n", x2);

   return 0;
}

/* add関数の定義 */
void add(int *x1, int *x2, int a)
{
  *x1 += a;
  *x2 += a;

}
