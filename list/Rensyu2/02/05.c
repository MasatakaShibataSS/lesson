#include <stdio.h>

int main(void)
{
	int  i = 0;            /* 行添字用 */
	int  j = 0;            /* 列添字用 */
  double  max = 0, min =0;
	double total = 0.0;    /* 性別合計用 */

    /* 配列の初期化 */
	double height[2][5] = {{ 160.0, 170.0, 180.7, 180.5, 180.0 },
						   { 160.0, 158.0, 155.8, 170.0, 151.0 }};


	for(i = 0; i < 2; i++, total = 0.0)                /* 行ループ */
	{
    total = max = min = height[i][0];

		for(j = 1; j < 5; j++)                         /* 列ループ */
		{
			total += height[i][j];
      if (max < height[i][j])
        max = height[i][j];
      if (min > height[i][j])
        min = height[i][j];

		}
		if(i == 0)                                     /* １行目 */
		{

      printf("男性最高: %.2f\n", max);
      printf("男性最低: %.2f\n", min);
			printf("男性平均: %.2f\n", total / j);
		}
		else
		{
      printf("\n");
      printf("女性最高: %.2f\n", max);
      printf("女性最低: %.2f\n", min);
			printf("女性平均: %.2f\n", total / j);
		}
	}

    return 0;
}
