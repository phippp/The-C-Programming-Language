/**
 * Exercise 1.16 - Longest
 *
 * Write a program to print the length of an arbitrarily long input line 
 * and as much text as possible
 * 
 **/

#include <stdio.h>

#define MAX 1000

int getline(char line[], int max);
void copy(char to[], char from[]);

main(){
    int len, max;
    char line[MAX], longest[MAX];

     max = 0;
    while((len = getline(line, MAX)) > 0){
        if(len > max){
            max = len;
        copy(longest, line);
        }
    }
    if (max > 0){
        printf("length = %i, string=%s", max, longest);
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

void copy(char to[], char from[]){
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}