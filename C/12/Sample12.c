#include <stdio.h>
#define NUM 8

int main(void)
{
  FILE *fp;
  int test[NUM];
  int max, min;
  int i,j;

  fp = fopen("test3.txt", "r");

  if(fp == NULL){
    printf("ファイルをオープンできませんでした。\n");
    return 1;
  }

  for(i=0; i<NUM; i++){
    fscanf(fp, "%d", &test[i]);
  }

  max = test[0];
  min = test[0];
  for(j=0; j<NUM; j++){
    if(max < test[j])
      max = test[j];
    if(min > test[j])
      min = test[j];
    printf("No.%-5d%d\n", j+1, test[j]);
  }

  printf("最高点は%dです\n", max);
  printf("最低点は%dです\n", min);



  fclose(fp);
   return 0;
}
