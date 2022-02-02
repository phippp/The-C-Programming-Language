#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

main()
{
    int c, state;
    state = OUT;

    //Exercise 1.12
    while((c = getchar()) != EOF) {
        if(c ==' ' || c == '\t')
        {
            state=OUT;
        }
        else if (state == OUT) 
        {
            state=IN;
            putchar('\n');
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }
}