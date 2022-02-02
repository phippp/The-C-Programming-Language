#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
    for(float fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%4.0f | %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}