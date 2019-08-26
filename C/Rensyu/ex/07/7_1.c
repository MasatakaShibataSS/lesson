#include <stdio.h>
#define NUM 5

int main(void)
{
int test[NUM];
int max;
int i, j;

max = 0;

printf("五人点数を入力してください。m(_ _)m\n");
for (i = 0; i < NUM; i++) {
  scanf("%d", &test[i]);

  if(max < test[i])
    max = test[i];
}
for (j = 0; j < NUM; j++) {
  printf("%d番目の人の点数は%dです。\n",j+1,test[j]);
}
  printf("最高点は%dです。\n", max);

   return 0;
}
