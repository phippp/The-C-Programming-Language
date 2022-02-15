/**
 * Exercise 1.18 - Trim
 *
 * Write a program to remove trailing blanks and tabs from
 * each line of input and delete entirely blank rows.
 * 
 **/

#include <stdio.h>

int getline(char line[], int limit);
int trim(char s[], int length);
void copy(char to[], char from[]);

#define MAXLENGTH 1000

main()
{
    int length;
    char current[MAXLENGTH];
    while((length = getline(current, MAXLENGTH)) > 0)
        if(trim(current, length) > 0)
            printf("%s", current);

}

int getline(char s[], int lim){
    int c, i;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int trim(char s[], int length){
    int i = length - 2;
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if(i >= 0){
        s[++i] = '\n';
        s[++i] = '\0';
    }
    return i;
}

void copy(char to[], char from[]){
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}