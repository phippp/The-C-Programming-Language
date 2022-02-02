#include <stdio.h>

main()
{
    int c;
    //Exercise 1.9
    while((c = getchar()) != EOF){
        if(c == '\t'){
            putchar('\\');
            putchar('t');
        } else if(c == '\\'){
            putchar('\\');
            putchar('\\');
        } else if(c == '\b'){
            putchar('\\');
            putchar('b');
        } else{
            putchar(c);
        }
    }
}