#include <stdio.h>

int main(void)
{
   FILE *fp;
   int i, j;

   fp = fopen("result.txt", "w");

   if(fp == NULL){
      printf("ファイルをオープンできませんでした。\n");
      return 1;
   }
   else{
      printf("ファイルをオープンしました。\n");
   }

   for (i=1; i<=5; i++){
      for(j=1; j<=5; j++){
         fprintf(fp, "%3d", i*j); 
      }
      fprintf(fp, "\n");
   }

   fclose(fp);
   printf("ファイルをクローズしました。\n");

   return 0;
}
