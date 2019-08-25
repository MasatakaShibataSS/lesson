#include <stdio.h>

int main(void)
{
    int cnt[10];
    int c;
    int i,s;

    for(i=0; i < 10; i++){
        cnt[ i ]= 0;
    }

    while ( (c = getchar( ) ) != EOF)     // Enter を押してからCtrl+d で入力終了.
    {
        if ( c >= '0' && c <= '9'){
            cnt[c - '0']++;               // 入力値が数字ならカウント
        }
    }
    printf("\n");

    for(i=0; i < 10; i++){
          printf("%1d", i);
      for(s=0; s < cnt[i]; s++){

      printf("*");
}

printf("\n" );
        /*printf("%1d : %d\n", i, cnt[ i ]);      // カウンタの表示 */
    }
    return 0;
}
