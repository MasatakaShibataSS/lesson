#include <stdio.h>

int main(void)
{
    int ary[5];    // 要素数5の配列.
    int i;
    for ( i = 0; i < 5; i++) {
      ary[i] = i+1;


  /*
    ary[0] = 1;
    ary[1] = 2;
    ary[2] = 3;
    ary[3] = 4;
    ary[4] = 5;
*/

      printf("ary[%d] = %d\n", i, ary[i]);
    }

 /*
    printf("ary[0] = %d\n", ary[0]);
    printf("ary[1] = %d\n", ary[1]);
    printf("ary[2] = %d\n", ary[2]);
    printf("ary[3] = %d\n", ary[3]);
    printf("ary[4] = %d\n", ary[4]);
 */
    return 0;
}
