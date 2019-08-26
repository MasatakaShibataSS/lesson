#include <stdio.h>
int main(void)
{
  int i;
  int sum = 0;
  fprintf(stderr, "ライン：%d\n", __LINE__);
  fprintf(stderr, "ソースファイル名：%s\n", __FILE__);
  fprintf(stderr, "作成日時：%s\n", __DATE__);
  fprintf(stderr, "作成時刻：%s\n", __TIME__);
  fprintf(stderr, "タイムスタンプ：%s\n", __TIMESTAMP__);
  fprintf(stderr, "ANSI C：%d\n", __STDC__);
  fprintf(stderr, "ライン：%d\n", __LINE__);

  for(i=1; i<=5; i++){
    sum = i + sum;
  }
  printf("1~5までの合計値は%dです。\n", sum);
   return 0;
}
