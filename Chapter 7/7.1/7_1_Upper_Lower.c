/**
 *
 * Exercise 7.1 - Upper Lower
 *
 * Write a program which converts upper case to lower case or lower case to 
 * upper case depending on the name it is involved with as found in argv[0]
 *
 **/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

main(int argc, char *args[])
{
    int c;
    if(strstr(args[0], "lower."))
        while((c = getchar()) != EOF)
            putchar(tolower(c));
    else
        while((c = getchar()) != EOF)
            putchar(toupper(c));

}