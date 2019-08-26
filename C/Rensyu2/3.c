#include <stdio.h>

int main(void){
  int res;
  printf("Please input month :");
  scanf("%d", &res);

  switch (res) {
    case 3:
    case 4:
    case 5:
    printf("Spring\n");
    break;
    case 6:
    case 7:
    case 8:
    printf("SUmmer\n");
    break;
    case 9:
    case 10:
    case 11:
    printf("Winter\n");
    break;
    case 12:
    case 1:
    case 2:
    printf("Winter\n");
        break;
        default:
          printf("Input error!\n");
          break;

  }
    return 0;
}
