/**
 * Exercise 2.4 - Squeeze
 *
 * Write a version of squeeze(s1,s2) that deletes each
 * character in the string 1 that matches any character in the string s2
 * 
 **/

#include <stdio.h>

#define MAXLENGTH 100

void squeeze(char line[], char alt[]);
int mgetline(char s[], int n);

main()
{
    char line[MAXLENGTH], s[MAXLENGTH];
    printf("Line 1 :\n");
    mgetline(line, MAXLENGTH);

    printf("Line 2 :\n");
    mgetline(s, MAXLENGTH);

    squeeze(line, s);
    printf("Result : %s", line);
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

void squeeze(char line[], char alt[]){
    int i, j, k;
    for(i = k = 0; line[i] != '\0'; ++i){
        for(j = 0; (line[i] != alt[j]) && alt[j] != '\0'; ++j)
            ; 
        if(alt[j] == '\0')
            line[k++] = line[i];
    }
    line[k] = '\0';
}