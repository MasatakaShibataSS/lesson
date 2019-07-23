#include <stdio.h>

int search(char str[]);

int main(void)
{
  char str[100];
  int ans;

  printf("文字列を入力してください。\n");
  scanf("%s", str);

  ans = search(str);

  printf("%sの中に＠は%d個含まれています\n",str, ans);
  return 0;

}

int search( char str[])
{
  int i, c;
  c = 0;

  for(i=0; str[i] != '\0'; i++)
  {
    if(str[i] == '@'){
      c++;
    }
  }
  return c;

}
