#include <stdio.h>

void fahrtocelcius(void);
void celsiustofahr(void);

#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
    celsiustofahr();
    printf("\n");
    fahrtocelcius();
}

void celsiustofahr()
{
    float fahr, celsius = LOWER;
    printf("%s | %s\n", "cels", "fahrenh");
    printf("-------------\n");
    while(celsius <= UPPER){
        fahr = celsius * (9.0 / 5.0) + 32.0;
        printf("%4.0f | %6.1f\n", celsius, fahr);
        celsius += STEP;
    }
}

void fahrtocelcius()
{
    float celsius, fahr = LOWER;
    printf("%s | %s\n", "fahr", "celsius");
    printf("-------------\n");
    while(fahr <= UPPER){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f | %6.1f\n", fahr, celsius);
        fahr += STEP;
    }
}