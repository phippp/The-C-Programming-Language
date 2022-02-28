/**
 *
 * Exercise 5.19 - Undcl
 *
 * Modify undcl so that it does not add redundant parenthesiss to declarations
 *
 **/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKEN 100
#define MAXSTRING 1000

enum { NAME, PARENS, BRACKETS};

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
int buffer[MAXSTRING];
int bufferloc = 0;
int previous = 0;
char out[MAXSTRING];

int gettoken();
int nexttoken();
int getch();
void ungetch(int);
void error(char *);

main()
{
    int type;
    char temp[MAXTOKEN];

    while(gettoken() != EOF){
        strcpy(out, token);
        while((type = gettoken()) != '\n')
            if(type == PARENS || type == BRACKETS){
                strcat(out, token);
            }else if(type == '*'){
                if((type = nexttoken()) == PARENS || type == BRACKETS){
                    sprintf(temp, "(*%s)", out);
                }else{
                    sprintf(temp, "*%s", out);
                }
                strcpy(out, temp);
            }else if (type == NAME){
                sprintf(temp, " %s %s", token, out);
                strcpy(out, temp);
            }else{
                printf("invalid input at %s \n",token);
            }
        printf("%s\n", out);
    }
}

int gettoken(){
    int c;
    char *p = token;
    if(previous){
        previous = 0;
        return tokentype;
    }
    while((c = getch()) == ' ' || c == '\t')
        ;
    if(c == '('){
        if((c = getch()) == ')'){
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if(c == '['){
        for(*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if(isalpha(c)){
        for(*p++ = c; isalnum(c = getch()); ){
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    return tokentype = c;
}

int nexttoken(){
    int type = gettoken();
    previous++;
    return type;
}

int getch(void){
    return (bufferloc > 0) ? buffer[--bufferloc] : getchar();
}

void ungetch(int c){
    if(bufferloc >= MAXSTRING)
        printf("Buffer full\n");
    else
        buffer[bufferloc++] = c;
}

void error(char *str){
    printf("ERROR: %s\n", str);
    previous++;
}