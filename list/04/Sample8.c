#include <stdio.h>

int main(void)
{
  int inum;
  double dnum;

  inum = 160;

  printf("身長は%dセンチです\n", inum);
  printf("double型の変数に代入します。\n");
  dnum = inum;
  printf("身長は%fセンチです\n", dnum);
   return 0;
}
