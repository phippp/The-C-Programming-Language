/**
 *
 * Exercise 1.4 - Conversion
 *
 * print Fahrenheit-Celsius table for celsius = 0, 20, ..., 300; 
 * floating-point version adding a header.
 *
 **/

#include <stdio.h>

main()
{
    float fahr, celsius; 
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;

    printf("%s | %s\n", "Celsius", "Fahr");
    printf("-------------\n");
    while(celsius <= upper){
        fahr = celsius * (9.0 / 5.0) + 32.0;
        printf("%7.0f | %4.1f\n", celsius, fahr);
        celsius += step;
    }
}