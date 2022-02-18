/**
 *
 * Exercise 3.6 - Padding
 * 
 * Write a version of itoa that accepts three arguments instead of two. 
 * The third argument is a minimum field width; the converted number 
 * must be padded with blanks on the left if necessary to make it wide enough.
 * 
 **/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itoa(int num, char loc[], int min);
void reverse(char s[]);
int abs(int n);

main()
{
    int number;
    char str[MAXLINE];
    number = -1234;
    itoa(number, str, 10);
    printf("%s", str);
}

int abs(int n){
    return (n > 0) ? n : (-n);
}

void itoa(int num, char loc[], int min){
    int i = 0;
    int original = num;
    do{
        loc[i++] = abs((num % 10)) + '0';
    }
    while((num /= 10) != 0);
    if(original < 0)
        loc[i++] = '-';
    while(i < min)
        loc[i++] = ' ';
    loc[i] = '\0';
    reverse(loc);
}

void reverse(char s[]){
    int temp, i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}