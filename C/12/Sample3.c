#include <stdio.h>

int main(void)
{
double num;

printf("小数を入力してください\n");
scanf("%lf", &num);

printf("小数点以下３ケタで出力すると%.2fです。\n", num);
printf("小数点以下３ケタで出力すると%-6.2fです。\n", num);

return 0;
}
