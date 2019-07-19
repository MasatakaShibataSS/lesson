#include <stdio.h>

/* compare関数の宣言 */
int compare(char str1[], char str2[]);

int main(void)
{
  char str1[100];
  char str2[100];
  int ans;

    printf("1番目の文字列を入力してください。\n");
    scanf("%s", str1);

    printf("2番目の文字列を入力してください。\n");
    scanf("%s", str2);

    ans = compare(str1, str2);

    if(ans ==1){
      printf("2つの文字列は同じです。\n" );
    }
    else
    {
      printf("2つの文字列は異なります。\n" );
    }

   return 0;
}

/* compare関数の定義 */
int compare(char str1[], char str2[])
{
  int i;

  for(i=0; str1[i] == str2[i]; i++){
    if(str1[i] == '\0'){
      return 1;
    }
  }
  return -1;
}
