#include <stdio.h>

int main(void)
{
  double dnum;
  int inum;

  dnum = 160.5;
  printf("身長は%fセンチです。\n", dnum);
  printf("int型に変数に代入します。\n");
  inum = dnum;
  printf("身長は%dセンチです。\n", inum);
  
   return 0;
}
