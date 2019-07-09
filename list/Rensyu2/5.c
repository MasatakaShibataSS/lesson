#include <stdio.h>

int main(void)
{
   int i;
   double data, total=0.0, average, max, min;

    total = max = min = data;

    for(i=1; i < 10; i++){
        scanf("%lf", &data);
        if( data > max)
            max = data;
        if( data < min)
            min = data;
        total += data;
    }

    average = total/10;

    printf("平均値: %f\n", average);
    printf("最大値: %f\n", max);
    printf("最小値: %f\n", min);

    return 0;
}
