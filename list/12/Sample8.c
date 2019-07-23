#include <stdio.h>

int main(void)
{
  FILE *fp;

  fp = fopen("test1.txt", "w");

  if(fp == NULL){
    printf("ファイルをオープンできませんでした。\n");
    return 1;
  }
  else{
    printf("ファイルをオープンしました。\n");
  }
  fclose(fp);
  printf("ファイルをクローズしました。", );
   return 0;
}
