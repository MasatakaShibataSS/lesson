#include <stdio.h>

/* 構造体型struct Personの宣言 */
typedef struct Person{
  int age;
  double t,w;
}Person;

int main(void)
{
  Person p[2];
  int i;

  for(i=0; i<2; i++){
  printf("年齢を入力してください\n");
  scanf("%d", &p[i].age);
  printf("身長を入力してください\n");
  scanf("%lf", &p[i].t);
  printf("体重を入力してください\n");
  scanf("%lf", &p[i].w);
}
  for(i=0; i<2; i++){
  printf("年齢%d 身長%f 体重%fです。\n", p[i].age, p[i].t, p[i].w);
}



   return 0;
}
