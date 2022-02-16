/**
 * Exercise 2.2 - Getline
 *
 * Write a loop equivalent for getline without using && and ||
 * This program prints the longest line in the given inputs
 * 
 **/

#include <stdio.h>

#define MAXLENGTH 1000

int mgetline(char line[], int lim);
void copy(char to[], char from[]);

main()
{
    char line[MAXLENGTH], longest[MAXLENGTH];
    int length, max = 0;
    while((length = mgetline(line, MAXLENGTH)) > 0){
        if(length > max){
            max = length;
            copy(longest, line);
        }
    }
    if(max > 0){
        printf("%s", longest);
    }
}

int mgetline(char s[], int lim){
    int c, i;
    for(i = 0; i < lim - 1; ++i){
        c = getchar();
        if(c == EOF) 
            break;
        if(c == '\n')
            break;
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}