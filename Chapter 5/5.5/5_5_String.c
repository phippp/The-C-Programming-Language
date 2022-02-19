/**
 *
 * Exercise 5.5 - String
 *
 * Write versions of the library functions strncpy, strncat, and
 * strncmp, which operate on at most the first n characters of their argument
 * strings.
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void mstrcpy(char *, char *, int);
void mstrcat(char *, char *, char *, int);
int mstrcmp(char *, char *, int);
int mstrlen(char *s);

main()
{
    char l1[] = "Hello ";
    char l2[] = "world";
    char l3[MAXLINE], l4[MAXLINE];
    int comp = mstrcmp(l1, l2, 1);
    printf("Compare :%d\n", comp);
    // - 47
    mstrcat(l1, l2, l3, 3);
    printf("Concat :%s\n", l3);
    // Hello wor
    mstrcpy(l4, l3, 7);
    printf("Copy :%s\n", l4);
    // Hello w
}

void mstrcat(char *s1, char *s2, char *dest, int num){
    while((*dest++ = *s1++) != '\0')
        ;
    dest--;
    while(num--){
        *dest++ = *s2++;
    }
    *dest = '\0';
}

void mstrcpy(char *dest, char *from, int num){
    while(num--){
        *dest++ = *from++;
    }
    *dest = '\0';
}

int mstrcmp(char *s1, char *s2, int num){
    for(; *s1 == *s2; s1++, s2++){
        if(--num <= 0 || *s1 == '\0')
            return 0;
    }
    return *s1 - *s2;
}