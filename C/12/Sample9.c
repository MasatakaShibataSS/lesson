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
  fputs("Hello!\n", fp);
  fputs("Goodby\n", fp);

  fclose(fp);
  printf("ファイルをクローズしました。\n");
   return 0;
}
