/**
 * Exercise 1.9 - Whitespace
 * 
 * write a program to replace each string of 1+ blanks
 * with a single blank.
 *
 **/

#include <stdio.h>

main()
{
    int c, last;
    last = 'a';
    while((c = getchar()) != EOF){
        if(c != ' ' || c != last)
            putchar(c);
        last = c;
    }
}