/**
 *
 * Exercise 4.13 - Reverse
 * 
 * a recursive version of revese(s)
 * 
 **/

#include<stdio.h>
#include<string.h>

void reverse(char s[]);

main()
{
    char line[] = "Hello World!";
    reverse(line);
    printf("%s", line);
}

void reverse(char str[]){
    void reverse_handler(char s[], int index, int length);
    reverse_handler(str, 0, strlen(str));
}

void reverse_handler(char str[], int index, int length){
    int opp = length - (index + 1);
    int temp;
    if(index < opp){
        temp = str[index];
        str[index] = str[opp];
        str[opp] = temp;
        reverse_handler(str, ++index, length);
    }
}