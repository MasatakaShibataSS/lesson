#include <stdio.h>

int main(void)
{
    int i;
    int ary1[5]={15, 30, 40};    // 配列の初期化.
    int ary2[5];

    // insert code here
  //  for (i = 0; i < 5; ++i) {
    //  ary2[i] = ary1[i];
      /* code */
    //}
    printf("ary1 ary2\n");
    printf("---------\n");

    for(i=0; i < 5; i++){
      ary2[i] = ary1[i];
        printf("%4d %4d\n", ary1[i], ary2[i]);
    }

    return 0;
}
