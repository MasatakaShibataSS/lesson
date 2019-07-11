#include <stdio.h>
#define NUM 6

int main(void)
{
    int i;
    int ary[NUM];
    int tmp;
    int k,m;

    for (i=0; i < NUM; i++){
        printf("ary[%d]: ", i);
        scanf("%d", &ary[i]);
    }
    m = NUM-1;
    for (k=0; k<NUM/2; k++){
      tmp = ary[k];
      ary[k] = ary[m-k];
      ary[m-k] = tmp;

    }


    for(i=0; i < NUM; i++){
        printf("ary[%d]=%d\n", i, ary[i]);
    }

    return 0;
}
