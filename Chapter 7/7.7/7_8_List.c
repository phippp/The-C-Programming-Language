/**
 *
 * Exercise 7.8 - List
 *
 * Write a program to print a set of files, starting each new one on a new page, 
 * with a title and a running page count for each file.
 *
 **/

#include <stdio.h>

#define MAXLINE 1000

main(int argc, char **args)
{
    int page = 0;
    char line[MAXLINE];
    FILE *file;

    while(*++args){
        if((file = fopen(*args, "r")) == NULL){
            printf("Can't open %s\n", *args);
            continue;
        }
        printf("Title : %s \tPage : %d\n\n", *args, ++page);
        while(fgets(line, MAXLINE, file) != NULL)
            printf("%s", line);
        printf("\n\n");
        fclose(file);
    }
}