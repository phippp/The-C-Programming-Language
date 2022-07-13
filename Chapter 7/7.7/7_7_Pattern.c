/**
 *
 * Exercise 7.7 - Pattern
 *
 * Modify the pattern finding program of Chapter 5 to take its input from a set of named files or,
 * if no files are named as arguments, from the standard input.
 * Should the file name be printed when a matching line is found?
 *
 **/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void sfile(FILE *, char *);

char pattern[] = "ll";

main(int argc, char **args)
{
    FILE *file;
    if(--argc == 0){
        file = stdin;
        sfile(file, pattern);
    } else {
        while(argc){
            if((file = fopen(*(++args), "r")) == NULL){
                printf("Can't open %s\n", *args);
                return 1;
            }
            sfile(file, pattern);
            argc--;
        }
    }
}

void sfile(FILE *file, char *p){
    char *ret, line[MAXLINE];
    int l = 0;
    while(*(ret = fgets(line, MAXLINE, file)) != EOF){
        if(strstr(line, p) != NULL){
            printf("line %d | %s\n", l, line);
        }
        l++;
    }
}