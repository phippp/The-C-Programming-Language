/**
 *
 * Exercise 2.7 - Invert
 * 
 * Write a function invert(x,p,n) that returns x with n bit starting at p
 * inverted .
 * 
 **/

#include <stdio.h>

unsigned invert(unsigned int x, int start, int count);

main()
{
    printf("%u", invert(8, 2, 3));
    // should print 15
}

unsigned invert(unsigned int x, int start_pos, int num){
     return x ^ ( ~( ~0 << num) << (start_pos + 1 - num));
}