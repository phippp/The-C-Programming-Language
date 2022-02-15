/**
 * Exercise 1.21 - Entab
 *
 * Write a Program entab that replaces strings of blanks by
 * the minimum number of tabs and blanks to achieve the same spacing.
 * 
 **/

#include <stdio.h>

#define TAB 8

main(){
    int c, blanks, tabs, counter;
    blanks = tabs = 0;
    for(counter = 1; (c = getchar()) != EOF ; ++counter){
        if(c == ' '){
            if((counter % TAB) != 0){
                ++blanks;
            }else{
                blanks = 0;
                ++tabs;
            }
        }else{
            for(; tabs > 0; --tabs)
                putchar('\t');
            blanks = (c == '\t') ? 0 : blanks;
            for(; blanks > 0; --blanks)
                putchar(' ');
            blanks = tabs = 0;
            putchar(c);
            if(c == '\n')
                counter = 0;
            else if(c == '\t')
                counter += (TAB - (counter - 1) % TAB) - 1;
        }
    }
}