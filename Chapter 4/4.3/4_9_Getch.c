/**
 *
 * Exercise 4.9 - Getch
 * 
 * getch and ungetch to handle EOF Character
 * 
 **/

/** 
 * So far all buffers have been char[], however to handle EOF
 * it has been changed to int[] so that it can handle EOF (-1)
 **/

#include <stdio.h>

#define BUFSIZE 100
#define MAXLINE 100

int getch(void); 
void ungetch(int c);

int buffer[BUFSIZE];
int bufferloc = 0;

main()
{
    int c = 'p';
    ungetch(c);
    while((c = getch()) != EOF)
        putchar(c);
    // should print 'p' before taking input
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