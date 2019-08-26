#include <stdio.h>

int main(void){
int a;
for (a = 1900; a <= 2017; a++) {
  if (a % 400 == 0 || (a % 4 == 0 && a %100 != 0)) {
    printf("%d ", a);
  }
}
printf("\n");
    return 0;
}
