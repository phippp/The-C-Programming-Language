/**
 *
 * Exercise 1.5 - Conversion
 *
 * print Fahrenheit-Celsius table for celsius = 300, 280, ..., 0; 
 * floating-point version.
 *
 **/

#include <stdio.h>

main()
{
    float celsius; 
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("%s | %s\n", "Fahr", "Celsius");
    printf("-------------\n");
    for(float fahr = upper; fahr >= lower; fahr -= step){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f | %6.1f\n", fahr, celsius);
    }
}