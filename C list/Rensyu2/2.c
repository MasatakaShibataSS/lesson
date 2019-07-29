#include <stdio.h>

int main(void){

    int dt = 100;
    dt = dt +1;
    // 通常の加算式の文
    printf("結果1= %d\n", dt);
    ++dt;
    // 前置型インクリメント演算子 の文
    printf("結果2= %d\n", dt);
    dt++;
    // 後置型インクリメント演算子の文
    printf("結果3= %d\n", dt);
    dt += 1;
    // 代入演算子の文
    printf("結果4= %d\n", dt);

    return 0;
}
