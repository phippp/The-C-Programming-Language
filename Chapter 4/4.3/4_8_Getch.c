/**
 *
 * Exercise 4.8 - Getch
 * 
 * Suppose that there will never be more than one character
 * for pushback. Modify getch and ungetch accordingly.
 * 
 **/

#include <stdio.h>

int getch(void); 
void ungetch(int c);

char buffer = 0;

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
    int c;
    if(buffer)
        c = buffer;
    else
        c = getchar();
    buffer = 0;
    return c;
}

void ungetch(int c){
    if(buffer)
        printf("Buffer full\n");
    else
        buffer = c;
}