/**
 *
 * Exercise 4.11 - Static
 * 
 * modify getop so that it does not need to use ungetch
 * 
 **/

#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define MAXLINE 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int index = 0;
double values[MAXVAL];
char line[MAXLINE];
int li = 0;

main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break; 
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Can't divide by 0\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Unknown command: %s\n", s);
                break;
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

int getop(char s[]){
    int c, i;
    static int lastc = 0;

    if(lastc == 0){
        c = getchar();
    }else{
        c = lastc;
        lastc = 0;
    }
    while((s[0] = c) == ' ' || c == '\t')
        c = getchar();
    
    s[1]='\0';
    
    if(!isdigit(c) && c!= '.')
        return c;
    
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getchar()))
            ;
    if(c == '.')
        while(isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if(c != EOF)
        lastc = c;
    return NUMBER;
}
