#include <stdio.h>

/* 構造体型struct Personの宣言 */
typedef struct Person{
  int age;
  double t,w;
}Person;

int main(void)
{
  Person p1, p2;
  printf("年齢を入力してください\n");
  scanf("%d", &p1.age);
  printf("身長を入力してください\n");
  scanf("%lf", &p1.t);
  printf("体重を入力してください\n");
  scanf("%lf", &p1.w);

  printf("年齢を入力してください\n");
  scanf("%d", &p2.age);
  printf("身長を入力してください\n");
  scanf("%lf", &p2.t);
  printf("体重を入力してください\n");
  scanf("%lf", &p2.w);

  printf("年齢%d 身長%f 体重%fです。\n", p1.age, p1.t, p1.w);
  printf("年齢%d 身長%f 体重%fです。\n", p2.age, p2.t, p2.w);




   return 0;
}
