#include <stdio.h>

main()
{
    int c;
    //Exercise 1.13
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c =='\n' || c == '\t')
            putchar('\n');
        else
            putchar('*');
    }
}