#include <stdio.h>

int main(void)
{
  char *str[3] = { "Hello", "Goodby", "Thankyou"};
  char *tmp;
  int i;

  for(i=0; i<3; i++){
    printf("文字列は%sです。\n", str[i]);
    printf("アドレスは%pです\n", &str[i]);
  }
  tmp = str[0];
  str[0] = str[2];
  str[2] = tmp;

  // str[0] = "1111111";
  // str[1] = "2222222";
  // str[2] = "3333333";
  for(i=0; i<3; i++){
    printf("文字列は%sです。\n", str[i]);
    printf("アドレスは%pです\n", &str[i]);
  }
   return 0;
}
