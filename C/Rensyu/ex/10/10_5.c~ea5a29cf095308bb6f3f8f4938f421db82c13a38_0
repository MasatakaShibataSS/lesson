#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char str[100];
  int i, j;

  printf("文字列を入力してください。\n");
  scanf("%s", str);
  for(i=0; str[i]!= '\0'; i++){
    str[i] = toupper(str[i]);
  }
  printf("大文字にすると%sです。\n", str);

  for(j=0; str[j]!= '\0'; j++){
    str[j] = tolower(str[j]);
  }
  printf("小文字にすると%sです。\n", str);

   return 0;
}
