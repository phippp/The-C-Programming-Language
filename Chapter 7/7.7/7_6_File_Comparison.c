/**
 *
 * Exercise 7.6 - File Comparison
 *
 * Write a program to compare two files, printing the first line where they differ.
 *
 **/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void filecmp(FILE *, FILE *);

main(int argc, char **args)
{
    FILE *file1, *file2;

    if(argc != 3){
        printf("Provide 2 files");
    } else {
        if((file1 = fopen(*(++args), "r")) == NULL){
            printf("Can't open %s\n", *args);
            return 1;
        }
        if((file2 = fopen(*(++args), "r")) == NULL){
            printf("Can't open %s\n", *args);
            return 1;
        }
        filecmp(file1, file2);
        fclose(file1);
        fclose(file2);
    }
}

void filecmp(FILE *f1, FILE *f2){
    char l1[MAXLINE], l2[MAXLINE];
    char *r1, *r2;
    int c;
    while(1){
        r1 = fgets(l1, MAXLINE, f1);
        r2 = fgets(l2, MAXLINE, f2);
        if((c = strcmp(l1, l2)) != 0 || *r1 == EOF || *r2 == EOF){
            break;
        }
    }
    printf("First difference:\n\t'%s'\n\t'%s'", l1, l2);

}