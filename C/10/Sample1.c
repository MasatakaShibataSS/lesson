#include <stdio.h>

int main(void)
{
  int test[5] = {80,60,55,22,75};
  int i;
  for (i = 0; i < 5; i++) {

      printf("test[%d]の値は%dです\n", i, test[i]);
      printf("test[%d]のアドレスは%pです\n", i, &test[i]);
  }



  /* printf("test[1]の値は%dです\n", test[1]);
  printf("test[1]のアドレスは%pです\n", &test[1]);
*/

   return 0;
}
