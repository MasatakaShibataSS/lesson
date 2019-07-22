/*
配列のソート
ポインタで処理
*/
#include <stdio.h>
int isort(int dir ,int len, int *ary)
{
    int tmp, i, j;
    int *p;
    for(i=0; i < len-1; i++, ary++){
        for(j=i+1,p=ary+1; j<len; j++, p++){
            if(dir){
                //昇順
                if(*ary > *p){
                    tmp = *ary;
                    *ary = *p;
                    *p = tmp;
                }
            }else{
                //降順
                if(*ary < *p){
                    tmp = *ary;
                    *ary = *p;
                    *p = tmp;
                }

            }
        }
    }

    return 0;
}


int main(void)
{
    int ary[]={30, -15, 20, 80, 90};
    int i;
    int len = sizeof(ary)/sizeof(ary[0]);

    isort(1, 5, ary);
    for(i=0; i<len; i++){
        printf("%d ", ary[i]);
    }
    printf("\n");

    isort(0, 5, ary);
    for(i=0; i<len; i++){
        printf("%d ", ary[i]);
    }
    printf("\n");

    return 0;
}
