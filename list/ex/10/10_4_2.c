#include <stdio.h>

/* search関数の宣言 */
int search(char *str);

int main(void)
{
  char str[100];
  int ans;

  printf("文字列を入力してください。\n");
  scanf("%s", str);

  ans = search(str);

  printf("%sの中に@は%d個ありますです。\n", str, ans);
   return 0;
}

/* search関数の定義 */
/*
int search(char *str)
{
  int  c = 0;

  while(*str){
    if(*str == '@'){
      c++;
    }
    str++;
  }
  return c;

}
*/

int search(char *str)
{
  int c =0;
  for(; *str; str++){
  if (*str == '@')
      c++;
  }
  str++;

  return c;
}
