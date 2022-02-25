/**
 *
 * Exercise 5.12 - Entab
 *
 * Extend entab to accept the shorthand entab -m +n to mean tab stops every 
 * n columns; starting at column m. Choose convenient size for the default behaviour
 * 
 **/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STANDARD_TAB 8
#define MAXLINE 80
#define YES 1

void parseArgs(int, char *[], int *);
int atoi(char *);
void entab(int *);

main(int argc, char *args[])
{
    int n;
    int tabs[MAXLINE];
    parseArgs(argc, args, tabs);
    entab(tabs);
}

void parseArgs(int c, char *args[], int *tabs){
    int i, num, start;
    printf("Running with %d args!\n", --c);
    // intialise as empty array
    for(i = 0; i < MAXLINE; i++)
        *(tabs + i) = 0;
    if(c == 2 && **(args + 1) == '-' && **(args + 2) == '+'){
        // upto 2 arguments passed
        start = atoi(&(*++args)[1]);
        num = atoi(&(*++args)[1]);
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

void entab(int *tab){
    int c,pos;
    int nb, nt; 
    nb = nt = 0;

    for(pos = 0; (c = getchar()) != EOF; pos++)
        if(c == ' '){
            if(!*(tab + pos)){
                ++nb;
            } else {
                nb = 0;
                ++nt;
            }
        } else {
            for(; nt ; nt--)
                putchar('\t');
            if(c == '\t')
                nb = 0;
            else
                for(; nb > 0;nb--)
                    putchar(' ');
            putchar(c);
            
            if(c == '\n')
                pos = 0;
            else if(c == '\t')
                while(!*(tab + pos))
                    ++pos;
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