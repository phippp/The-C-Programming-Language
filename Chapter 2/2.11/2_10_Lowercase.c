/**
 *
 * Exercise 2.10 - Lowercase
 * 
 * Function lower(c) using conditional expression
 * 
 **/

#include <stdio.h>

int lower(int c);

main()
{
    int c;
    while(( c= getchar()) != EOF)
        putchar(lower(c));
}

int lower(int c){
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}