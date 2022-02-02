#include <stdio.h>

main()
{
    float fahr, celsius; 
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    //Exercise 1.3
    printf("%s | %s\n", "fahr", "celcius");
    printf("-------------\n");
    while(fahr <= upper){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f | %6.1f\n", fahr, celsius);
        fahr += step;
    }

    printf("\n");

    //Exercise 1.4
    printf("%s | %s\n", "cels", "fahrenh");
    printf("-------------\n");
    celsius = lower;
    while(celsius <= upper){
        fahr = celsius * (9.0 / 5.0) + 32.0;
        printf("%4.0f | %6.1f\n", celsius, fahr);
        celsius += step;
    }
}