#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *str;
  int num, i;
  // char ary[10];
  // str=ary;

  printf("何文字のaを用意しますか？\n");
  scanf("%d", &num);

  str = (char *) malloc (sizeof(char) * (num+1));
  if(!str){
    printf("メモリが確保できませんでした。\n");
    return 1;

  }

  for (i=0; i<num; i++) {
    *(str+i) = 'a';
  }
  *(str+i) ='\0';
  printf("%sを用意しました\n", str);

  free(str);

   return 0;
}
