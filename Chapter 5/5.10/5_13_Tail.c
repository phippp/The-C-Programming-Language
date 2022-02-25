/**
 *
 * Exercise 5.13 - Tail
 *
 * Write a Program tail, which prints the last n lines of its input. By default n is 10.
 * let us say; but it can be changed by an optional argument so that tail -n
 *
 **/

#include <stdio.h>
#include <ctype.h>

#define DEFAULT_LINES 10
#define MAXLENGTH 100

int atoi(char *);
int maxlines(int, char *[]);
int mgetline(char *, int);
void copy(char *, char *);

main(int argc, char *args[])
{
    int len, i, c = 0;
    const int num = maxlines(argc, args);
    char input[MAXLENGTH];
    char buffer[num][MAXLENGTH];
    printf("%d lines:\n", num);
    while ((len = mgetline(input, MAXLENGTH)) > 0){
        if(c < num){
            copy(*(buffer + c++), input);
        }else{
            for(i = 0; i < num - 1; i++){
                copy(*(buffer + i), *(buffer + i + 1));
            }
            copy(*(buffer + i), input);
        }
    }
    for(i = 0; i < c; i++)
        printf("%s", *(buffer + i));
}

int maxlines(int c, char *args[]){
    if (--c != 1 || **(args + 1) != '-')
        return DEFAULT_LINES;
    return atoi(&(*++args)[1]);
}

int atoi(char *line){
    int sign, c, val = 0;
    for (; isspace(*line); line++)
        ;
    sign = *line == '-' ? -1 : 1;
    if (*line == '-' || *line == '+')
        line++;
    while (isdigit(c = *line++)){
        val = (val * 10) + (c - '0');
    }
    return val * sign;
}

int mgetline(char *s, int lim){
    int c;
    char *t = s;
    while (--lim && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

void copy(char *to, char *from){
    while((*to++ = *from++) != '\0')
        ;
}