#include <stdio.h>
int imax(int len, int *ary)
{
    int _max, i;
    _max = *ary++;
    for(i=1; i<len; i++, ary++){
        if( _max < *ary)
            _max = *ary;
    }

    return _max;
}


int imin(int len, int *ary)
{
    int _min, i;
    _min = *ary++;
    for(i=1; i<len; i++, ary++){
        if( _min > *ary)
            _min = *ary;
    }

    return _min;
}

int main(void)
{
    int ary[]={30, 15, 20, 80, 90};
    int x;

    x = imax(sizeof(ary)/sizeof(ary[0]), ary);
    printf("最大値: %d\n", x);

    x = imin(sizeof(ary)/sizeof(ary[0]), ary);
    printf("最小値: %d\n", x);

    return 0;
}

 
