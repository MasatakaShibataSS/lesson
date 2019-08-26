#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[10];
    char str2[10];
    char *str3;

    strcpy(str1,"Hello");
    strcpy(str2,"Goodby");

    printf("配列str1は%sです。\n", str1);
    printf("配列str2は%sです。\n", str2);

  /*  strcpy(str1, str2);
    printf("配列str1は%sです。\n", str1);
*/
    str3 = strcpy(str1, str2);
    printf("配列str1は%sです。\n", str1);
    printf("配列str3は%sです。\n", str3);
   return 0;
}
