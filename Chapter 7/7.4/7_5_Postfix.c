/**
 *
 * Exercise 7.5 - Postfix
 *
 * Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf 
 * to do the input and number conversion.
 *
 **/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXVAL 100

void push(double);
double pop(void);

int index = 0;
double values[MAXVAL];

main()
{
    char e = '\0', *c, s[MAXVAL], buf[MAXVAL];
    double a = 0, op2;
    while(scanf("%s%c", s, &e) == 2){
        if(sscanf(s, " %lf", &a) == 1)
            push(a);
        else if(sscanf(s, "%s", buf)){
            for(c = buf; *c; c++){
                switch (*c){
                    case '+':
                        push(pop() + pop());
                        break;
                    case '-':
                        op2 = pop();
                        push(pop() - op2);
                        break;
                    case '*':
                        push(pop() * pop());
                        break;
                        case '/':
                        op2 = pop();
                        if(op2 != 0.0)
                            push(pop() / op2);
                        else
                            printf("Error : division by 0");
                        break;
                    default:
                        printf("Unknown command");
                        break;
                }
            }
            if(e == '\n')
                printf("\t%.8g\n", pop());
        }
    }
}

void push(double f){
    if(index < MAXVAL)
        values[index++]=f;
    else
        printf("Stack is full! Can't push %g\n", f);
}

double pop(void){
    if(index > 0){
        return values[--index];
    } else {
        printf("Stack is empty!\n");
        return 0.0;
    }
}