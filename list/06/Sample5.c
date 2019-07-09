#include <stdio.h>

int main(void)
{
  int i = 1;
  int num;
  printf("何回繰り返しますか？\n");
  scanf("%d", &num);

  while(i <= num){
    printf("%d番目の繰り返しです。\n", i);
    i++;
  }
  printf("繰り返しが終わりました。\n");
   return 0;
}
