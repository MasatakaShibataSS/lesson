#include <stdio.h>

int main(void)
{
	char ch;
	printf("文字を入力してください。（英数字）\n");
	ch = getchar();
	printf("%cが入力されました。\n", ch);

   return 0;
}
