/**
 *
 * Exercise 7.2 - Escape
 *
 * Write a Program that will print arbitrary input in a sensible way.As a
 * minimum, it should print non-graphic character in octal or hexadecimal
 * according to the local customer and break long text lines
 *
 **/

#include<stdio.h>
#include<ctype.h>

#define MAXLINE 100

int increment(int, int);

main()
{
    int pos = 0, c;
    while((c = getchar()) != EOF){
        if(iscntrl(c) || c == ' '){
            pos = increment(pos, 6);
            printf("\\%03o",c);
            if(c == '\n')
                pos = 0;
            putchar('\n');
        } else {
            pos = increment(pos,1);
            putchar(c);
        }
    }
}

int increment(int pos, int num){
    if(pos + num < MAXLINE){
        return pos + num;
    } else {
        putchar('\n');
        return num;
    }
}