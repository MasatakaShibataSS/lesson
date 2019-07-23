#include <stdio.h>

/* 構造体型struct Carの宣言 */
typedef struct Car{
  int num;
  double gas;
  struct Car *next;
}Car;

int main(void)
{
  Car car0;
  Car car1;
  Car car2;
  Car *pcar;

  car0.num = 0000; car0.gas = 00.00;
  car1.num = 1111; car1.gas = 11.11;
  car2.num = 2222; car2.gas = 22.22;

  car0.next = &car1;
  car1.next = &car2;
  car2.next = NULL;

  for(pcar = &car0; pcar!=NULL; pcar = pcar->next)
{
  printf("車のナンバーは%dです。ガソリン量は%lfです。\n", pcar->num, pcar->gas);
}
Car car3;
car3.num = 6666; car3.gas = 66.66;
car0.next = &car3;
car3.next = &car1;

printf("***car3 insert***\n");
for(pcar = &car0; pcar!=NULL; pcar = pcar->next)
{
printf("車のナンバーは%dです。ガソリン量は%lfです。\n", pcar->num, pcar->gas);
}
car0.next = &car1;
printf("***delete***\n");
for(pcar = &car0; pcar!=NULL; pcar = pcar->next)
{
printf("車のナンバーは%dです。ガソリン量は%lfです。\n", pcar->num, pcar->gas);
}
   return 0;
}
