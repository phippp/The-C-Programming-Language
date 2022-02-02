#include <stdio.h>

main()
{
    int c, last;
    last = 'a';
    //Exercise 1.9
    while((c = getchar()) != EOF){
        if(c != ' ' || c != last)
            putchar(c);
        last = c;
    }
}