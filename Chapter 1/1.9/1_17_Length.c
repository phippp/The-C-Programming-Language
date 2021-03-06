/**
 * Exercise 1.17 - Length
 *
 * Program to print the length of all input lines greater
 * than 80 characters.
 * 
 **/

#include <stdio.h>

int getline(char line[], int limit);
void copy(char to[], char from[]);

#define MAXLENGTH 1000

main()
{
    int length;
    char current[MAXLENGTH];
    while((length = getline(current, MAXLENGTH)) > 0)
        if(length > 80)
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

void copy(char to[], char from[]){
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}