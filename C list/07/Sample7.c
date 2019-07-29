#include <stdio.h>
#include <string.h>
int main(void)
{
  /*

 char str[10];
 str[0]='H';
 str[1]='e';
 str[2]='l';
 str[3]='l';
 str[4]='o';
 str[5]='\0';
*/
char str[10] = "HELLO";
//har str[] = "Hellooooi";添字は省略可
 printf("%sは文字列です。\n", str);

 strcpy(str,"goodbye");
 printf("%sは文字列です。\n", str);

  return 0;
}
