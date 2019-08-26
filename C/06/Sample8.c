#include <stdio.h>

int main(void)
{
  int i, j;

  for(i=0; i<5; i++){
    for(j=0; j<3; j++){
      printf("iは%d:jは%d\n", i, j);
    }
  }

   return 0;
}
