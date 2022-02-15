/**
 * Exercise 1.8 - Whitespace
 * 
 * write a program to count blanks, tabs and newlines
 *
 **/

#include <stdio.h>

main()
{
    int c, ws = 0;
    while((c = getchar()) != EOF){
        if(c == '\t' || c == ' ' || c == '\n')
            ws++;
    }
    printf("There were %d whitespace characters", ws);
}