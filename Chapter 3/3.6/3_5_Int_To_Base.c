/**
 *
 * Exercise 3.5 - Int To Base
 * 
 * Write the function itob(n,s,b) that converts the integer n 
 * into a base b character representation in the string s. 
 * In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
 * 
 **/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itob(int num, char loc[], int base);
void reverse(char s[]);
int abs(int n);

main()
{
    int number;
    char str[MAXLINE];
    number = 267;
    itob(number, str, 16);
    printf("%s", str);
}

int abs(int n){
    return (n > 0) ? n : (-n);
}

void itob(int num, char loc[], int base){
    int j, i = 0;
    int original = num;
    do{
        j = abs((num % base));
        loc[i++] = j > 9 ? j + 'a' - 10 : j + '0';
    }
    while((num /= base) != 0);
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