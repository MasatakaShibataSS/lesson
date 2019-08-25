#include <stdio.h>
#define NUM 5

int main(void)
{
  FILE *fp;
  int test[NUM];
  int i, j;

  fp = fopen("test2.txt", "w");

  if(fp == NULL){
    printf("ファイルをオープンできませんでした。\n");
    return 1;
  }
  else{
    printf("ファイルをオープンしました。\n");
  }

  printf("%d人の点数を入力してください。\n", NUM);
  for(i=0; i<NUM; i++){
    scanf("%d", &test[i]);
  }
  for(j=0; j<NUM; j++){
    fprintf(fp, "No.%-5d%d\n", j+1, test[j]);
  }
  printf("ファイルに書き込みました。\n");
  fclose(fp);
  printf("ファイルをクローズしました。\n");
   return 0;
}
