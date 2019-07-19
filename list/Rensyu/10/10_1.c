#include <stdio.h>

/* length関数の宣言 */
int length(char str[]);

int main(void)
{
  char str[100];
  int ans;

  printf("文字列を入力してください。\n");
  scanf("%s", str);

  ans = length(str);

  printf("文字列の長さは%dです。\n", ans);

   return 0;
}

/* length関数の定義 */
int length(char str[])
{
  int i, c;
  c = 0;
  for (i = 0; str[i]!='\0'; i++) {
    c++;
  }

  return c;
}
