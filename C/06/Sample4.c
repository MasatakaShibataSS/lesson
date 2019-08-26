#include <stdio.h>

int main(void)
{
  int num, sum;
  //int i;

  num = 0;
  sum =0;

  printf("いくつまでの合計を求めますか？\n");
  scanf("%d", &num);

  for(int i=1; i<=num; i++){
  //for(int i=1; i<num; i++){

    sum += i;
  }
  printf("0から%dまでの合計値は%dです。 \n", num, sum);
  //printf("0から%dまでの合計値は%dです。 \n", num-1, sum);

   return 0;
}
