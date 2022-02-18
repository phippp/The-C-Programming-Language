/**
 *
 * Exercise 3.3 - Expand
 * 
 * Write a function expand(s1,s2) that expands shorthand notations 
 * like a-z in the string s1 into the equivalent complete list abc…xyz in s2.
 * 
 **/

#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[],int maxline);
void expand(char from[], char to[]);

main()
{
    char line[MAXLINE], result[MAXLINE];
    mgetline(line, MAXLINE);
    expand(line, result);
    printf("%s", result);
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

void expand(char from[], char to[]){
    int c, i, j;
    i = j = 0;
    while((c = from[i++]) != '\0'){
        if(from[i] == '-' && from[i + 1] >= c){
            i++;
            while(c < from[i]){
                to[j++] = c++;
            }
        } else {
            to[j++] = c;
        }
    }
    to[j] = '\0';
}