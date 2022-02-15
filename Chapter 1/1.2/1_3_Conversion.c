/**
 *
 * Exercise 1.3 - Conversion
 *
 * print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; 
 * floating-point version.
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

    fahr = lower;

    printf("%s | %s\n", "Fahr", "Celcius");
    printf("-------------\n");
    while(fahr <= upper){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f | %6.1f\n", fahr, celsius);
        fahr += step;
    }
}