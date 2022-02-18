/**
 *
 * Exercise 3.4 - Int To ASCII (itoa)
 * 
 * Modified version of itoa
 * 
 **/

/** 
 * In twos complement the MIN_INT is -2147483648, whilst the MAX_INT is only 2147483647
 * So n=-n would fail for this scenario.
 **/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itoa(int num, char loc[]);
void reverse(char s[]);
int abs(int n);

main()
{
    int number;
    char str[MAXLINE];
    number = -2147483648;
    itoa(number, str);
    printf("%s", str);
}

int abs(int n){
    return (n > 0) ? n : (-n);
}

void itoa(int num, char loc[]){
    int i = 0;
    int original = num;
    do{
        loc[i++] = abs((num % 10)) + '0';
    }
    while((num /= 10) != 0);
    if(original < 0)
        loc[i++] = '-';
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