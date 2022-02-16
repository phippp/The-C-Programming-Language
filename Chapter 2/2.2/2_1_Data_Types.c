/**
 * Exercise 2.1 - Data Types
 *
 * Program to print maximum, minimum limits of char, int, long using
 * calculation
 * 
 **/

#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
    /* SIGNED Maximum Values */

    printf("Min Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
    // replaceable by SCHAR_MIN
    printf("Max Char %d\n",(char) ((unsigned char) ~0 >> 1));
    // replaceable by SCHAR_MAX

    printf("Min Short %d\n",-(short)((unsigned short)~0 >>1) -1);
    // replaceable by SHRT_MIN
    printf("Max Short %d\n",(short)((unsigned short)~0 >> 1));
    // replaceable by SHRT_MAX

    printf("Min Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
    // replaceable by INT_MIN
    printf("Max Int %d\n",(int)((unsigned int)~0 >> 1));
    // replaceable by INT_MAX

    printf("Min Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
    // replaceable by LONG_MIN
    printf("Max Long %ld\n",(long)((unsigned long)~0 >> 1));
    // replaceable by LONG_MAX

    /* UNSIGNED Maximum Values */

    printf("Max u_Char %d\n",(unsigned char)~0);
    // replaceable by UCHAR_MAX
    printf("Max u_Short %d\n",(unsigned short)~0);
    // replaceable by USHRT_MAX
    printf("Max u_Int %u\n",(unsigned int)~0);
    // replaceable by UINT_MAX
    printf("Max u_Long %lu\n\n",(unsigned long)~0);
    // replaceable by ULONG_MAX

}