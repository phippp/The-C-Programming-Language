/**
 *
 * Exercise 5.6 - Recap
 *
 * Rewrite appropriate programs from earlier chapters 
 * and exercises with pointers instead of array indexing
 *
 **/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define NUMBER '0' 
#define MAXVAL 100 
#define BUFSIZE 100
#define MAXLINE 1000
#define MAXOP 100

int getch();
void ungetch(int);
int getop(char *);
void push(double);
double pop();

int mgetline(char *, int);
int strindex(char *, char *);
int atoi(char *);
void itoa(int , char *);
void reverse(char *);

int ind = 0;
int bufferloc = 0;
double values[MAXVAL];
char buffer[BUFSIZE];

main()
{
    char line[] = "Hello World";
    char find[] = "lo";
    char feed[MAXLINE];
    char number[] = "  -1234";
    int num = -9876;
    printf("%d\n", strindex(line, find));
    // 3 
    reverse(line);
    printf("%s\n", line);
    // dlroW olleH
    mgetline(feed, MAXLINE);
    printf("%s\n", feed);
    // 
    printf("%d\n", atoi(number));
    // -1234
    itoa(num, feed);
    printf("%s\n", feed);
    // -9876
    int type;
    double temp;
    char calculator[MAXOP];

    while((type = getop(calculator)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(calculator));
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
                if( temp != 0.0)
                    push(pop() / temp);
                else
                    printf("Can't divide by 0\n");
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                printf("Unknown command %s\n",calculator);
                break;
        }
    }
}

int getop(char *s){
    int c, i;

    while((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1)='\0';
    
    if(!isdigit(c) && c != '.')
        return c;
    
    i = 0;
    if(isdigit(c))
        while(isdigit(*++s = c = getchar()))
            ;
    if(c == '.')
        while(isdigit(*++s = c = getchar()))
            ;
    *s = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

int mgetline(char *line, int max){
    char c;
    char *s = line;
    while(max-- && (c = getchar()) != EOF && c != '\n')
        *line++ = c;
    if(c == '\n')
        *line++ = c;
    *line = '\0';
    return line - s;
}

void reverse(char *line){
    int temp;
    char *p;
    for(p = line + strlen(line) - 1; line < p; p--, line++){
        temp = *line;
        *line = *p;
        *p = temp;
    }
}

int strindex(char *s, char *t){
    char *p, *q, *b = s;
    for(; *s != '\0'; s++){
        for(p = s, q = t; *q == *p && *p != '\0'; p++,q++ )
            ;
        if(q > t && *q =='\0')
            return s - b;
    }
    return -1;
}

int atoi(char *line){
    int sign, c, val = 0;
    for(;isspace(*line); line++)
        ;
    sign = *line == '-' ? -1 : 1;
    if(*line == '-' || *line == '+')
        line++;
    while(isdigit(c = *line++)){
        val = (val * 10) + (c - '0');
    }
    return val * sign;
}

void itoa(int num, char *loc){
    char *start = loc;
    int original = num;
    do{
        *loc++ = abs((num % 10)) + '0';
    }
    while((num /= 10) != 0);
    if(original < 0)
        *loc++ = '-';
    *loc = '\0';
    reverse(start);
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

void push(double f){
    if(ind < MAXVAL)
        values[ind++] = f;
    else
        printf("Stack is full! Can't push %g\n", f);
}

double pop(void){
    if(ind > 0){
        return values[--ind];
    } else {
        printf("Stack is empty!\n");
        return 0.0;
    }
}