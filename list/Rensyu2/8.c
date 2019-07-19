#include <stdio.h>

int imax(int len, int ary[])
{
    int _max, i;
    //iny ary[]の最大値_maxを返すコードを記述してください
    _max = ary[0];
   for(i=1; i<len; i++){
       if( _max < ary[i])
           _max = ary[i];
   }

    return _max;
}

int imin(int len, int ary[])
{
    int _min, i;
    //iny ary[]の最小値_minを返すコードを記述してください
    _min = ary[0];
   for(i=1; i<len; i++){
       if( _min > ary[i])
           _min = ary[i];
   }

    return _min;
}

int main(void)
{
    int ary[]={30, -15, 20, 80, 90};
    int x;

    x = imax(sizeof(ary)/sizeof(ary[0]), ary);
    printf("最大値: %d\n", x);

    x = imin(sizeof(ary)/sizeof(ary[0]), ary);
    printf("最小値: %d\n", x);

    return 0;
}
