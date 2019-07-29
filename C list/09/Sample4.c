 #include <stdio.h>

int main(void)
{
  int a, b;
  int *pA;

  a = 5;
  b = 10;

  pA = &a;

  printf("変数aの値は%dです。\n", a);
  printf("ポインタpaの値は%pです。\n", pA);
  printf("*pAの値は%dです。\n", *pA);

  pA = &b;
  // pA++;
  // pA += 1;

  printf("変数bの値は%dです。\n", b);
  printf("ポインタpaの値は%pに変更されました。\n", pA);
  printf("*pAの値は%dです。\n", *pA);

   return 0;
}
