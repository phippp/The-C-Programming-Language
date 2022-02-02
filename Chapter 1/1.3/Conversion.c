#include <stdio.h>

main()
{
    float celsius; 
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    //Exercise 1.5

    printf("%s | %s\n", "fahr", "celcius");
    printf("-------------\n");
    for(float fahr = upper; fahr >= lower; fahr -= step){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f | %6.1f\n", fahr, celsius);
    }
}