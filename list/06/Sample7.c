#include <stdio.h>

int main(void)
{
  int i = 1;
  do {
    printf("%dの繰り返しです。\n", i);
    i++;
  } while(i <= 5);


  printf("繰り返しが終わりました。\n");
   return 0;
}
