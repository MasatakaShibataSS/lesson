#include <stdio.h>

int main(void)
{
 char str[] = "Hello";
 int i;

 printf("Hello\n");
/*
 for(i=0; str[i]!='\0'; i++){
   printf("%c*", str[i]);
 }*/
 i=0;
 while(str[i]){
   printf("%c*", str[i]&0xdf);
   //&0xdfでASCIIコードを使って大文字に変換
   i++;
 }
 printf("\n");
 printf("文字の長さは%dです。\n", i);

  return 0;
}
