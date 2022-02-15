/**
 * Exercise 1.10 - Escaping
 * 
 * Write a Program to copy its input to its output,
 * replacing each tab by \t, each backspace by \b, and each backslash by \\.
 * This makes tabs and backspaces visible in an unambiguous way.
 *
 **/

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