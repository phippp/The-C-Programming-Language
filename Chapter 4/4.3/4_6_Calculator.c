/**
 *
 * Exercise 4.6 - Calculator
 * 
 * Add command for handling variables
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
#define FUNC 'f'

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void checkfunc(char []);

int index = 0;
double values[MAXVAL];
char buffer[BUFSIZE];
int bufferloc = 0;

main()
{
    int type, var = 0;
    double op2, v;
    char s[MAXOP];
    double variable[26];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case FUNC:
                checkfunc(s);
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
            case '=':
                pop();
                if(var >= 'A' && var <= 'Z')
                    variable[var - 'A'] = pop();
                else
                    printf("Not a valid variable name\n");
                break;
            case '\n':
                printf("\t%.8g\n", (v = pop()));
                break;
            default:
                if(type>='A' && type<='Z')
                    push(variable[type-'A']);
                else if(type =='v')
                    push(v);
                else
                    printf("Unknown Command %s\n",s);
                break;
        }
        var = type;
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
    if(islower(c)){
        while(islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if(c != EOF)
            ungetch(c);
        if(strlen(s) > 1)
            return FUNC;
        else 
            return s[0];
    }
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
        printf("Buffer already full\n");
    else
        buffer[bufferloc++] = c;
}

void checkfunc(char s[]){
    double op2;
    if(strcmp(s, "sin") == 0){
        push(sin(pop()));
    }else if(strcmp(s, "cos") == 0){
        push(cos(pop()));
    }else if(strcmp(s, "exp") == 0){
        push(exp(pop()));
    }else if(strcmp(s, "pow") == 0){
        op2 = pop();
        push(pow(pop(), op2));
    }
    else{
        printf("%s is not supported\n",s);
    }
}

