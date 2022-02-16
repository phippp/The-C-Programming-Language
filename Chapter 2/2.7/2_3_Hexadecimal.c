/**
 * Exercise 2.3 - Hexadecimal
 *
 * Write a program that converts a hex string to integer
 * 
 **/

#include<stdio.h>

#define MAXLINE 100

int mgetline(char line[], int limit);
int htoi(char line[]);

main()
{
    int length;
    char line[MAXLINE];
    while((length = mgetline(line, MAXLINE)) > 0){
        printf("The value of '%s' is %d\n", line, htoi(line));
    }

}

int mgetline(char s[], int lim){
    // removed any final line breaks so it can
    // be used in printf without adding a line break.
    int c, i;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}

int htoi(char s[]){
    int i, n;
    i = n = 0;
    if(s[i] == '0'){
        ++i;
        if(s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    for(; 1; ++i){
        if(s[i] >= '0' && s[i] <= '9')
            n = (n * 16) + (s[i] - '0');
        else if(s[i] >= 'a' && s[i] <= 'f')
            n = (n * 16) + (s[i] - 'a' + 10);
        else if(s[i] >= 'A' && s[i] <= 'F')
            n = (n * 16) + (s[i] - 'A' + 10);
        else
            break;
    }
    return n;
}
