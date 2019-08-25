#include <stdio.h>
#define NUM 5

int main(void)
{
  FILE *fp;
  int num;
  int i;

  fp = fopen("test1.bin", "rb");

  if(fp == NULL){
    printf("ファイルをオープンできませんでした。\n");
    return 1;
  }
  printf("何番目のデータを読み込みますか？\n");
  scanf("%d", &i);
  
  fseek(fp, (i-1)*sizeof(int), SEEK_SET);
  fread(&num, sizeof(int), 1, fp);

  printf("%d番目のデータは%dです。\n", i, num);
  fclose(fp);

  return 0;
}
