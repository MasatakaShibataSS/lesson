#include <stdio.h>

int main(void)
{
	double num1;
	double num2;
	printf("身長を入力してください\n" );
	scanf ("%lf", &num1);
	printf("体重を入力してください\n" );
	scanf ("%lf", &num2);
	printf("身長は%fセンチです。\n", num1);
	printf("体重は%fキロです。\n", num2);
 
   return 0;
}
