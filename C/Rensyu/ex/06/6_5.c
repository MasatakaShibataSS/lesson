#include <stdio.h>

int main(void)
{
  int num, i;

  printf("2以上の整数を入力してください。\n");
  scanf("%d", &num);

  for(i=2; i<=num; i++){
    if(i == num){
      printf("%dは素数です。\n", num);
    }
    else if((num % i) == 0){
      printf("%dは素数ではありません。\n", num);
      break;
    }
  }

   return 0;
}
