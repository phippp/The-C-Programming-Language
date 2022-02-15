/**
 * Exercise 1.13 - Histogram
 * 
 * Print a horizontal histogram of words in the input.
 * 
 **/

#include <stdio.h>

main()
{
    int c;
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c =='\n' || c == '\t')
            putchar('\n');
        else
            putchar('*');
    }
}