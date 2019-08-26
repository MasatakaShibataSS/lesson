#include <stdio.h>

int main(void)
{
  int a;
  scanf("%d", &a);
  if(a&1)
    printf("odd\n");
  else
    printf("even\n");
    

  return 0;
}
