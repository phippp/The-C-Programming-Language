#include <stdio.h>

main()
{
    int ws, c;
    ws = 0;
    //Exercise 1.8
    while((c = getchar()) != EOF){
        if(c == '\t' || c == ' ' || c == '\n')
            ws++;
    }
    printf("There were %d whitespace characters", ws);
}