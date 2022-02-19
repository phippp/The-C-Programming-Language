/**
 *
 * Exercise 5.3 - Stend
 * 
 * Write the function strend(s,t), which returns 1 if 
 * the string t occurs at the end of the string s, and zero otherwise.
 * 
 **/

#include <stdio.h>

#define MAXLINE 1000

int mstrend(char *, char *);
int mstrlen(char *);
int mgetline(char [], int);

main()
{
    int end;
    char line1[MAXLINE], line2[MAXLINE];
    mgetline(line1, MAXLINE);
    mgetline(line2, MAXLINE);
    end = mstrend(line1, line2);
    printf("Result: %s", end ? "true" : "false");
}

int mstrend(char *l1, char *l2){
    char *e1 = l1 + mstrlen(l1) - 1;
    char *e2 = l2 + mstrlen(l2) - 1;
    while(*(e1) == *(e2)){
        --e1;
        --e2;
    }
    e2++;
    return e2 == l2;
}

int mstrlen(char *l1){
    char *iter = l1;
    while(*(iter++) != '\0')
        ;
    return iter - l1;
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