#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  char ch;

  if(argc < 2){
    printf("パラメータの数が違います。\n");
    return 1;
  }

  for(int i=0; i<argc; i++)
  printf("argv[%d]:%s\n",i,argv[i] );


  fp = fopen(argv[1], "r");

  if(fp == NULL){
    printf("ファイルをオープンできませんでした。\n");
    return 1;
  }

  while((ch=fgetc(fp)) != EOF){
    putchar(ch);
  }

  fclose(fp);


   return 0;
}
