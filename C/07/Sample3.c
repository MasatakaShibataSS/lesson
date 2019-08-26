#include <stdio.h>

int main(void)
{
  //int test[5] = {80,60,22,50,75};
  //省略可能
  //int test[] = {80,60,22,50,75};
  int test[5] = {80,60,22,50};

  int i;

  for(i=0; i<5; i++){
    printf("%d番目の人の点数は%dです。\n", i+1, test[i]);
  }

   return 0;
}
