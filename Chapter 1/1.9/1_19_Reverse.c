/**
 * Exercise 1.19 - Reverse
 *
 * Write a function reverse(s) that reverses the character 
 * string s. Use it to write a program that reverses its
 * input a line at a time.
 * 
 **/

#include <stdio.h>

int getline(char line[], int limit);
void reverse(char s[]);
void copy(char to[], char from[]);

#define MAXLENGTH 1000

main()
{
    int length;
    char current[MAXLENGTH];
    while((length = getline(current, MAXLENGTH)) > 0){
        reverse(current);
        printf("%s", current);
    }
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

void reverse(char s[]){
    int i, j, temp;
    for(i = 0; s[i] != '\0'; i++)
        ;
    --i;
    if(s[i] == '\n') --i;
    j = 0;
    do {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
    while(++j < --i);
}

void copy(char to[], char from[]){
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}