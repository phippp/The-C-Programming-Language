/**
 *
 * Exercise 4.10 - Getline
 * 
 * Revise the Calculator program to use the getline instead 
 * of getch and ungetch
 * 
 **/

#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define MAXVAL 100
#define MAXLINE 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
int mgetline(char s[], int n);

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
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push(fmod(pop(), op2));
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
     int c,i;

    if(line[li] == '\0')
        if(mgetline(line, MAXLINE) == 0)
            return EOF;
        else
            li =0;
    while((s[0] = c = line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = line[li++]))
            ;
    if( c == '.')
        while(isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    li--;
    return NUMBER;
}

int mgetline(char s[], int n){
    int c, i;
    for(i = 0; i < n - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}