/**
 *
 * Exercise 4.1 - String Index
 * 
 * Write the function strindex(s,t) which returns the position of the 
 * rightmost occurrence of t in s, or -1 if there is none.
 * 
 **/

#include <stdio.h>

int strindex(char str[], char find[]);

main()
{
    char str[] = "ewweeeqweewqwweeqwewwee";
    char find[] = "qwe";
    printf("%s was found at index %d in %s", find, strindex(str,find), str);
}

int strindex(char str[], char find[]){
    int i, j, k, r;
    r = -1;
    for(i = 0;str[i] != '\0'; i++){
        for(j = i, k = 0; find[k] != '\0' && find[k] == str[j]; j++, k++)
            ;
        if(k > 0 && find[k] == '\0')
            r = i;
    }
    return r;
}
