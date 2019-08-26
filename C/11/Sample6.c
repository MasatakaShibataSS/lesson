#include<stdio.h>

/* 構造体型struct Carの宣言 */
typedef struct Car{
	int num;
	double gas;
}Car;


int main(void)
{
	printf("int型のサイズは%ldバイトです\n", sizeof(int));
	printf("double型のサイズは%ldバイトです\n", sizeof(double));
	printf("構造体型struct Car型のサイズは%ldバイトです\n", sizeof(Car));
	printf("構造体型struct Car型へのサイズは%ldバイトです\n", sizeof(Car *));

   return 0;
}
