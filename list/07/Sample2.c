#include <stdio.h>

int main(void)
{
  int test[6];
  int i, j;


  printf("6人点数を入力してください。m(_ _)m\n");
  for(i=0; i<6; i++){
    scanf("%d", &test[i]);
  }
  for(j=0; j<6; j++){
    printf("%d番目の人の点数は%dです。\n", j+1, test[j]);
  }

   return 0;
}
