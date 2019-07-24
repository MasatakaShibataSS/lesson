#include <stdio.h>
#define NUM 5

int main(void)
{
  int test[NUM] = {80,60,22,50,75};
  int size[NUM];
  int i,j;

  size[j] = sizeof(test[i]);

for(i=0; i<5; i++){
  printf("%d\n", test[i]);
  printf("%d\n", size[j]);

}
printf("%ld\n", sizeof(int));

  return 0;
}
