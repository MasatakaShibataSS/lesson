#include <stdio.h>

int main(void)
{
  int num = 0;
  int sum = 0;


  printf("科目１の点数を入力してください\n");
  scanf("%d", &num);
  sum += num;

  printf("科目2の点数を入力してください\n");
  scanf("%d", &num);
  sum += num;

  printf("科目3の点数を入力してください\n");
  scanf("%d", &num);
  sum += num;

  printf("科目4の点数を入力してください\n");
  scanf("%d", &num);
  sum += num;

  printf("科目5の点数を入力してください\n");
  scanf("%d", &num);
  sum += num;

  printf("５科目の合計点は%dです。\n", sum);
  printf("５科目の平均点は%fです。\n", (double)sum/5);

   return 0;
}
