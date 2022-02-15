/**
 * Exercise 1.6 - EOF
 * 
 * verify that the expression getchar() != EOF is 0 or 1
 *
 **/

#include <stdio.h>

main()
{
    int c;
    while((c = getchar()) != EOF){
        printf("%c : %d\n", c, c != EOF);
    }

    printf("%d", c != EOF);

    //Exercise 1.7
    printf("%d", EOF);
}