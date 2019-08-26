#include <stdio.h>

int main(void)
{
	double num;
	printf("円周率の値はいくつですか？\n");
	scanf("%lf", &num);

	printf("円周率は%.3fです。\n", num);

   return 0;
}
