/**
 *
 * Exercise 5.3 - Strcat
 * 
 * Write a pointer version of the function strcat 
 * that we showed in Chapter 2: 
 * strcat(s,t) copies the string t to the end of s.
 * 
 **/

#include <stdio.h>

#define MAXLINE 1000

void mstrcat(char *, char *);
int mgetline(char [], int);

main()
{
    char line1[MAXLINE], line2[MAXLINE];
    mgetline(line1, MAXLINE);
    mgetline(line2, MAXLINE);
    mstrcat(line1, line2);
    printf("Result: %s", line1);
}

void mstrcat(char *l1, char *l2){
    while(*(l1++) != '\0')
        ;
    l1--;
    while((*(l1++) = *(l2++)) != '\0')
        ;
}

int mgetline(char s[], int n){
    int c, i;
    for(i = 0; i < n - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}