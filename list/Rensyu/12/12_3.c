#include <stdio.h>

int main(int argc, char* argv[])
{
   FILE *fp;
   int i, j;

   if(argc != 2){
     printf("パラメータの数が違います。\n");
     return 1;
   }

   fp = fopen(argv[1], "w");

   if(fp == NULL){
     printf("ファイルをオープンできませんでした。\n");
     return 1;
   }
   else{
     printf("ファイルをオープンしました。\n");
   }
   for (i = 1; i <= 5; i++) {
     for (j = 1; j <= 5; j++) {
       fprintf(fp, "%5d", i*j);
     }
     fprintf(fp, "\n");
   }
fclose(fp);
printf("ファイルをクローズしました。\n");

   return 0;
}
