/**
 * Exercise 1.14 - Character Counter
 * 
 * Print a histogram of the frequencies of different
 * characters in an input.
 * 
 **/

#include <stdio.h>

#define CHARS 128

main()
{
    int c, i, j;
    int counter[CHARS];

    for(i = 0; i < CHARS; i++)
        counter[i] = 0;

    while((c = getchar()) != EOF)
        counter[c]++;

    for(i = 0; i < CHARS; i++)
    {
        putchar(i);
        for(j = 0; j < counter[i]; ++j)
        {
            putchar('*');
        }
        putchar('\n');
    }

}