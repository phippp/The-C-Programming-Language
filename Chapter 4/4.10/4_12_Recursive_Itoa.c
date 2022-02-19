/**
 *
 * Exercise 4.12 - Recursive Itoa
 * 
 * recursive version of itoa; that converts an integer string by calling a recursive routine
 * 
 **/

#include<stdio.h>
#include<math.h>

#define MAXSIZE 100

void itoa(int n,char s[]);

main()
{
    int n = 1723;
    char line[MAXSIZE];
    itoa(n, line);
    printf("%s", line);
}

void itoa(int n, char s[]){
    static int i;
    if(n / 10){
        itoa(n / 10, s);
    } else {
        i = 0;
        if(n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}