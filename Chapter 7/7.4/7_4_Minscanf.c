/**
 *
 * Exercise 7.4 - Minscanf
 *
 * Write a private version of scanf analogous to minprintf
 * from the previous section.
 *
 **/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

void minscanf(char*, ...);

main()
{
    char s[1000];
    int i;
    float f;

    printf("Enter a float, a string and an integer:\n");
    minscanf("%f %s %d", &f, s, &i);
    printf("minscanf: \nfloat: %f\nstring: %s\ninteger: %d\n", f, s, i);
}

void minscanf(char *fmt,...){
    va_list ap;
    char *p, *sptr, sval[1000];
    int *iptr, ival;
    float *fptr, fval;

    va_start(ap, fmt);  
    
    for(p = fmt; *p; p++){
        if(*p != '%')
            continue;
        switch(*++p){
            case 'd':
                iptr = va_arg(ap, int *);
                scanf("%d", &ival);
                *iptr = ival;
                break;
            case 'f':
                fptr = va_arg(ap, float *);
                scanf("%f", &fval);
                *fptr = fval;
                break;
            case 's':
                sptr = va_arg(ap, char *);
                scanf("%s", sval);
                strcpy(sptr, sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}