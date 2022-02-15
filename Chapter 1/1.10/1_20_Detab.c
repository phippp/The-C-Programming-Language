/**
 * Exercise 1.20 - Detab
 *
 * Write a Program detab, which replaces tabs in the input with a proper
 * number of blanks to spaces
 * 
 **/

#include <stdio.h>

#define TAB 8

main(){
    int c, counter, i;
    counter = 1;
    while((c = getchar()) != EOF){
        if(c == '\t'){
            for(i =  TAB - ((counter - 1) % TAB); i > 0; --i, ++ counter)
                putchar(' ');
        } else {
            if(c == '\n')
                counter = 0;
            putchar(c);
            counter++;
        }
    }
}