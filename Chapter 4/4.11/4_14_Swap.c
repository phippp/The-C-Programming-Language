/**
 *
 * Exercise 4.14 - Swap
 * 
 * a macro swap(t,x,y) that interchanges two arguments of type t
 * 
 **/

#include<stdio.h>
#include<string.h>

#define swap(type, x, y) { type _temp; \
                            _temp = x; \
                            x = y; \
                            y = _temp; }

void reverse(char s[]);

main()
{
    int x = 100, y = 50;
    printf("X: %d and Y: %d\n", x, y);
    swap(int, x, y);
    printf("X: %d and Y: %d\n", x, y);
}
