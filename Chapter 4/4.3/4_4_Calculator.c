/**
 *
 * Exercise 4.4 - Calculator
 * 
 * Add commands to: 
 * - print top element of the stack, without poping '?'
 * - duplicate it 'd'
 * - swap the top two elements 's'
 * - clear the stack 'c'
 * 
 **/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
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

int index = 0;
double values[MAXVAL];
char buffer[BUFSIZE];
int bufferloc = 0;

main()
{
    int type;
    double op2, op1;
    char str[MAXOP];
    while ((type = getop(str)) != EOF) {
        switch (type) {
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
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("Can't divide by 0\n");
                break;
            case 's':
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'c':
                index = 0;
                break;
            case '?':
                op2 = pop();
                printf("\t%.8g\n",op2);
                push(op2);
                break;
            case 'd':
                op2 = pop();
                push(op2);
                push(op2);
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