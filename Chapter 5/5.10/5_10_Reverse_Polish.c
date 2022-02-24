/**
 *
 * Exercise 5.10 - Reverse Polish
 *
 * Write a program exprcmd, which evaluates a reverse polish expression,
 * from the command line,where each operator or operand is a seperate argument
 *
 **/

/**
 * Currently doesnt seem to parse * as a argument via command line:
 * It gets replaced by any files in that directory.
 * This appears to be a problem with the shell rather than code see.
 * https://stackoverflow.com/questions/63311501/asterisk-in-c-console-lists-all-files-in-folder-why
 * With my current shell escaping doesnt work. However, after testing on macOS 
 * with bash I was able to escape it as \* or '*' and both worked fine.
 * As a replacement I have also added 'x' as a way to multiply for convenience.
 */

#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>
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
void ungets(char *);

double values[MAXVAL];
int index = 0;
char buffer[BUFSIZE];
int bufferloc = 0;

main(int argc, char *args[])
{
    int c;
    double temp;
    char str[MAXOP];
    while (--argc) {
        ungetch(' ');
        ungets(*++args);
        switch (c = getop(str)) {
            case NUMBER:
                push(atof(str));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
            case 'x':
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
            default:
                printf("Unknown command: %c\n", c);
                argc = 1;
                break;
        }
    }
    printf("\t%.8g\n", pop());
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

void ungets(char *s){
    char *m = s + strlen(s) - 1;
    while(m >= s){
        ungetch(*m--);
    }
}