#include <stdio.h>
#define NUM 5

int main(void)
{
  FILE *fp;
  int test[NUM] = {65536,60,22,50,75};
  int i;

  fp = fopen("test1.bin", "wb");

  if(fp == NULL){
    printf("ファイルをオープンできませんでした。\n");
    return 1;
  }

  for(i=0; i<NUM; i++){
    fwrite(&test[i], sizeof(int), 1,fp);
  }
  printf("ファイルに書き込みました。\n");

  fclose(fp);

  return 0;
}
