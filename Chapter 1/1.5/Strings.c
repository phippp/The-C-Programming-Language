#include <stdio.h>

main()
{
    int c;

    //Exercise 1.6
    while((c = getchar()) != EOF){
        putchar(c);
        printf("%d", c != EOF);
    }

    printf("%d", c != EOF);

    //Exercise 1.7
    printf("%d", EOF);
}