/**
 *
 * Exercise 3.2 - Escape
 * 
 * Write a function escape(s,t) that converts characters like newline and tab 
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * 
 **/

#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[],int maxline);
void escape(char to[], char from[]);

main()
{
    char line[MAXLINE], escaped[MAXLINE], unescaped[MAXLINE];
    mgetline(line, MAXLINE);
    escape(escaped, line);
    printf("%s", escaped);
}

void escape(char to[], char from[]){
    int c, i;
    c = i = 0;

    while(from[i] != '\0'){
        switch (from[i])
        {
        case '\t':
            to[c++] = '\\';
            to[c++] = 't';
            break;
        case '\n':
            to[c++] = '\\';
            to[c++] = 'n';
            break;
        default:
            to[c++] = from[i];
            break;
        }
        i++;
    }
    to[c] = '\0';
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