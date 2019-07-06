#include <stdio.h>

int main(void)
{
 int i=0;
 a:
   printf("A\n");
   i++;
   if(i < 5) goto a;
   printf("END\n");
//comment
//comment2
   return 0;
}
