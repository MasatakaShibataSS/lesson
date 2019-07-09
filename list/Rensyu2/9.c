#include <stdio.h>

int main(void)
{
int i, j;
scanf("Input number", &i);

for(i=1; i<=5; i++){
  for(j=4; j<i; j++){
    printf("*");
  }
  printf("\n");
}
   return 0;
}
