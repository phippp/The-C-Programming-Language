/**
 *
 * Exercise 2.6 - Setbits
 * 
 * Write a function setbits(x,p,n,y) that returns x with the
 * n bits that begin at positionp set to the rightmost n bits of y,leaving
 * the other bits unchanged.
 * 
 **/

#include <stdio.h>

unsigned setbits(unsigned x, int start, int count, unsigned alt);

main()
{
    printf("%u\n", setbits(8, 2, 2, 15));
    // should print 14
}

unsigned setbits(unsigned x, int s, int c, unsigned alt){
    unsigned modified_x = x & ~(~(~0 << c) << (s + 1 - c));
    unsigned modified_alt = alt & (~(~0 << c) << (s + 1 - c));
    return modified_x | modified_alt;
}