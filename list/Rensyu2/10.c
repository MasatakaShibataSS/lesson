/*
配列のソート関数
 dir: 降順昇順の切り替え
　　1: 昇順ソート
    0: 降順ソート
*/
#include <stdio.h>
int isort(int dir ,int len, int ary[])
{
    int tmp, i, j;
    for(i=0; i < len-1; i++){
        for(j=i+1; j<len; j++){
            if(dir){
                //昇順
                if(ary[i] > ary[j]){
                    tmp = ary[i];
                    ary[i] = ary[j];
                    ary[j] = tmp;
                }
            }else{
                //降順
                if(ary[i] < ary[j]){
                    tmp = ary[i];
                    ary[i] = ary[j];
                    ary[j] = tmp;
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
