#include <stdio.h>

int main(void)
{
  int i, j, ch;
  ch = 1;
  //ch = '-';

  for(i=0; i<4; i++){
    for(j=0; j<5; j++){
    //  ch = (ch == '*') ? '-':'*';
      printf("%c",ch);
      //putchar(ch);

      if(ch == 0){
        printf("*");
        ch =1;
      }
      else{
        printf("-");
        ch = 0;

      }
    }
    printf("\n");
  }

   return 0;
}
