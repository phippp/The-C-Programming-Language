/**
 *
 * Exercise 4.7 - Ungets
 * 
 * Write a routine ungets(s) that will push back an entire string onto
 * the input. Should ungets(s) know about buf and bufp or
 * should it handle it to ungetch()
 * 
 **/

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
#define MAXLINE 100

int getch(void); 
void ungetch(int c);
void ungets(char s[]);
int mgetline(char line[], int maxline);

char buffer[BUFSIZE];
int bufferloc = 0;

main()
{
    char line[MAXLINE];
    int c;
    mgetline(line, MAXLINE);
    ungets(line);
    while((c = getch()) != EOF){
        putchar(c);
    }
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

int getch(void){
    return (bufferloc > 0) ? buffer[--bufferloc] : getchar();
}

void ungetch(int c){
    if(bufferloc >= BUFSIZE)
        printf("Buffer full\n");
    else
        buffer[bufferloc++] = c;
}

void ungets(char s[]){
    int i = strlen(s);
    while(i)
        ungetch(s[--i]);
}