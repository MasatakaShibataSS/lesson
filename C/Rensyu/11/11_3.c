#include <stdio.h>

/* 構造体型struct Personの宣言 */
typedef struct Person{
  int age;
  double t,w;
}Person;
/* aging関数の宣言 */
void aging(Person *r);
int main(void)
{
  Person p1;
  printf("年齢を入力してください\n");
  scanf("%d", &p1.age);
  printf("身長を入力してください\n");
  scanf("%lf", &p1.t);
  printf("体重を入力してください\n");
  scanf("%lf", &p1.w);

  printf("年齢%d 身長%f 体重%fです。\n", p1.age, p1.t, p1.w);

  aging(&p1);

  printf("1年経ちました。\n");
  printf("年齢%d 身長%f 体重%fです。\n", p1.age, p1.t, p1.w);
   return 0;
}

/* aging関数の定義 */
void aging(Person *r){
  r->age++;


}
