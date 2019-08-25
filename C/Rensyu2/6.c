#include <stdio.h>

int main(void)
{
    int cnt=0;
    double data, total=0.0, average;

    scanf("%lf", &data);

    while(data >= 0) {
        total += data;
        cnt++;
        scanf("%lf", &data);
    }

    if(cnt != 0){
        average = total/cnt;
        printf("平均値: %f\n", average);
    }else{
        printf("No data \n");
    }

    return 0;
}
