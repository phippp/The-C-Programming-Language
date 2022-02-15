/**
 * Exercise 1.22 - Fold
 *
 * Write a program to "fold" long input lines into two or more 
 * shorter lines after the last non-blank character that occurs
 * before the n-th column of input.
 * 
 **/

#include <stdio.h>

#define MAXCOL 35
#define TAB 8

int lastblank(char arr[], int len);

main()
{
    int c, i, j, counter, column, i_lastblank;
    char line[MAXCOL + 1];
    
    counter = column = 0;
    while ((c = getchar()) != EOF) {
        line[counter++] = c;
        column += (c == '\t') ? (TAB - (column % TAB)) : 1;
        if (column >= MAXCOL || c == '\n') {
            line[counter] = '\0';
            if ((i_lastblank = lastblank(line, counter)) == -1) {
                for (i = 0; i < counter; ++i)
                    putchar(line[i]);
                column = counter = 0;
            }
            else {
                for (i = 0; i < i_lastblank; ++i)
                    putchar(line[i]);
                for (i = i_lastblank + 1, column = 0; i < counter; ++i) {
                    line[i - (i_lastblank + 1)] = line[i];
                    column += (c == '\t') ? (TAB - (column % TAB)) : 1;
                }
                counter = i - (i_lastblank + 1);
            }
            putchar('\n');
        }
    }
}

int lastblank(char arr[], int len)
{
    int i;
    for (i = len; i > 0; --i)
        if (arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\n')
            return i;
    return -1;
}