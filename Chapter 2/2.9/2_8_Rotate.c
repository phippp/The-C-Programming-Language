/**
 *
 * Exercise 2.7 - Invert
 * 
 * Write a function rightrot(x,n) that returns the value of the 
 * integer x rotated to rightby n bit positions
 * 
 **/

#include <stdio.h>

unsigned rightrot(unsigned x,int n);
int wordsize(void);

main()
{
    printf("%u\n", rightrot(8, 1));
    printf("%u\n", rightrot(9, 1));
}

unsigned rightrot(unsigned x,int n){
    unsigned right = x << (wordsize() - n);
    x >>= n;
    x |= right;
    return x;
}

int wordsize(){
    unsigned x = ~0;
    int b;
    for(b = 0; x; b++)
        x &= x-1;
    return x;
}