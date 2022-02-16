/**
 * Exercise 2.5 - Any
 *
 * Write the function any(s1,s2) which returns the first location in the string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains
 * no characters from s2. ( The standard library function strpbrk does
 * the same job but retuns a pointer to the location
 * 
 **/

#include <stdio.h>

#define MAXLENGTH 100

int any(char in[], char s[]);
int mgetline(char s[], int n);

main()
{
    char line[MAXLENGTH], s[MAXLENGTH];
    printf("Line 1 :\n");
    mgetline(line, MAXLENGTH);

    printf("Line 2 :\n");
    mgetline(s, MAXLENGTH);

    printf("Result : %d", any(line, s));
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

int any(char in[], char s[]){
    int i, j, k;
    for(i = k = 0; in[i] != '\0'; ++i){
        for(j = 0; (in[i] != s[j]) && s[j] != '\0'; ++j)
            ; 
        if(s[j] != '\0' && s[j] != '\n')
            return i;
    }
    return -1;
}