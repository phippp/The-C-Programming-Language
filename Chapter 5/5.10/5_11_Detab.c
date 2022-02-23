/**
 *
 * Exercise 5.11 - Detab
 *
 * Modify the program detab (written as exercises in Chapter 1) to accept 
 * a list of tab stops as arguments. Use the default tab settings if there are no arguments.
 *
 **/

/**
 * Accepts:
 *      no args         -> offset = 0, spacing = 8 (every 8 space starting from 0)
 *      1 arg (n)       -> offset = 0, spacing = n (every n spaces starting from 0)
 *      2 args (m, n)   -> offset = n, spacing = m (every n spaces starting from m)
 *      n args          -> each arg is an index for tab spaces
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STANDARD_TAB 8
#define MAXLINE 80
#define YES 1

void parseArgs(int, char *[], int *);
int atoi(char *);
void detab(int *);

main(int argc, char *args[])
{
    int n;
    int tabs[MAXLINE];
    parseArgs(argc, args, tabs);
    detab(tabs);
}

void parseArgs(int c, char *args[], int *tabs){
    int i, num, start;
    printf("Running with %d args!\n", --c);
    // intialise as empty array
    for(i = 0; i < MAXLINE; i++)
        *(tabs + i) = 0;
    if(c <= 2){
        // upto 2 arguments passed
        num = c > 0 ? atoi(*++args) : STANDARD_TAB;
        start = c > 1 ? atoi(*++args) : 0;
        printf("Start index: %d\nEvery: %d\n", start, num);
        for(i = start; i < MAXLINE; i += num)
            *(tabs + i) = YES;
    } else {
        // loop through all argumets
        while(--c){
            num = atoi(*++args);
            if(num < MAXLINE)
                *(tabs + num) = YES;
        }
    }
}

void detab(int *tabs){
    int c, pos = 0;
    while((c = getchar()) != EOF){
        if(pos >= MAXLINE || c == '\n'){
            putchar('\n');
            pos = 0;
        } else if(c == '\t'){
            do
                putchar(' ');
            while(*(tabs + ++pos) != YES && pos < MAXLINE);
        }else{
            putchar(c);
            ++pos;
        }
    }
}

int atoi(char *line){
    int sign, c, val = 0;
    for(;isspace(*line); line++)
        ;
    sign = *line == '-' ? -1 : 1;
    if(*line == '-' || *line == '+')
        line++;
    while(isdigit(c = *line++)){
        val = (val * 10) + (c - '0');
    }
    return val * sign;
}

int mgetline(char *line, int max){
    char c;
    char *s = line;
    while(max-- && (c = getchar()) != EOF && c != '\n')
        *line++ = c;
    if(c == '\n')
        *line++ = c;
    *line = '\0';
    return line - s;
}