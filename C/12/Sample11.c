#include <stdio.h>
#define NUM 20

int main(void)
{
  FILE *fp;
  char str1[NUM];
  char str2[NUM];

  fp = fopen("test1.txt", "r");

  if(fp == NULL){
    printf("ファイルをオープンできませんでした。\n");
    return 1;
  }
  else{
    printf("ファイルをオープンしました。\n");
  }

  fgets(str1, NUM-1, fp);
  fgets(str2, NUM-1, fp);

  printf("ファイルに書き込まれている文字列は\n");
  printf("%s", str1);
  printf("%s", str2);

  fclose(fp);
  printf("ファイルをクローズしました。\n");
   return 0;
}
