#include <stdio.h>
int  main()
{
    int  i, c;
    c=' ';
    for(i=32; i < 127; i++) {
	putchar(c++);
        if(c%16==0) putchar('\n');
    }
    putchar('\n');
    return 0;
}

 
