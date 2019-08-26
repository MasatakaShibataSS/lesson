#include <stdio.h>

int main(void)
{
  int res;
  int i;
   printf("何番目でループを中止しますか？（１〜１０）\n");

   scanf("%d", &res);
   for(int j=0; j<3; j++){
     for (i=1; i<=10; i++) {
       printf("%d番目の処理です。\n", i);
       if(i == res)
       break;
    }
  }
   return 0;
}
