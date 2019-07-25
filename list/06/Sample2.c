#include <stdio.h>

int main(void)
{
 int i;
 int j =1;

 for(i=0; i<5; i++,j++){
   printf("%dの繰り返しです\n", j);
 }

 printf("繰り返しが終わりました。\n");
   return 0;
}
