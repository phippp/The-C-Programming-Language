/**
 *
 * Exercise 4.3 - Calculator
 * 
 * Adding the Modulus operator and provision for negative numbers 
 * 
 **/

#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

double values[MAXVAL];
int index = 0;
char buffer[BUFSIZE];
int bufferloc = 0;

main()
{
    int c;
    double temp;
    char str[MAXOP];
    while ((c = getop(str)) != EOF) {
        switch (c) {
            case NUMBER:
                push(atof(str));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                temp = pop();
                push(pop() - temp);
                break; 
            case '/':
                temp = pop();
                if (temp != 0.0)
                    push(pop() / temp);
                else
                    printf("Can't divide by 0\n");
                break;
            case '%':
                temp = pop();
                if(temp != 0.0)
                    push(fmod(pop(), temp));
                else
                    printf("Can't divide by 0\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Unknown command: %s\n", str);
                break;
        }
    }
}

void push(double f){
    if(index < MAXVAL)
        values[index++] = f;
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
    int i,c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    i = 0;
    if(!isdigit(c) && c != '.' && c != '-')
        return c;

    if(c=='-')
        if(isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else
        {
            if(c != EOF)
                ungetch(c);
            return '-';
        }
    
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;

    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void){
    return (bufferloc > 0) ? buffer[--bufferloc] : getchar();
}

void ungetch(int c){
    if(bufferloc >= BUFSIZE)
        printf("Buffer full\n");
    else
        buffer[bufferloc++] = c;
}