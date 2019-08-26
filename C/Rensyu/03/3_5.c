#include <stdio.h>

int main(void)
{
	double num1;
	double num2;
	printf("身長と体重を入力してください\n" );
	scanf ("%lf", &num1);
	scanf ("%lf", &num2);
	printf("身長は%fセンチ：体重は%fです。\n", num1, num2);
 
   return 0;
}
