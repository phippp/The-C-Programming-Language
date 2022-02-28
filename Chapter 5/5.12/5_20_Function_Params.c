/**
 *
 * Exercise 5.20 - Function Params
 *
 * Expand dcl to handle declarations with function argument types, qualifiers like const, and so on.
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
char *types[] = { "char", "int", "void"};
char *modifiers[] = { "const", "volatile"};

void dcl();
void dirdcl();
void paramdcl();
int gettoken();
int getch();
void ungetch(int);
void error(char *);
int validtype();
int validmod();


main()
{
    while(gettoken() != EOF){
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if(tokentype != '\n')
            printf("Sytntax Error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
}

void dcl(){
    int ns;
    for(ns = 0; gettoken() == '*'; ns++)
        ;
    dirdcl();
    while(ns--)
        strcat(out, " pointer to");
}

void dirdcl(){
    int type;
    if(tokentype == '('){
        dcl();
        if(tokentype != ')')
            error("Missing ')'");
    } else if(tokentype == NAME){
        strcpy(name, token);
    }else{
        error("Expected name or (dcl)");
    }
    while((type = gettoken()) == PARENS || type == BRACKETS || type == '('){
        if(type == PARENS){
            strcat(out, " function returning");
        } else if(type == '('){
            strcat(out, " funtion expecting");
            paramdcl();
            strcat(out, " and returning");
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

void paramdcl(){
    char t[MAXTOKEN];
    do{
        t[0] = '\0';
        gettoken();
        do{
            if(tokentype != NAME){
                previous++;
                dcl();
            }else if(validtype() || validmod()){
                strcat(t, " ");
                strcat(t, token);
                gettoken();
            }else{
                error("Unknown parameter");
            }
        }while(tokentype != ',' && tokentype != ')');
        strcat(out, t);
        if(tokentype == ',')
            strcat(out, ",");
    } while(tokentype == ',');
    if(tokentype != ')')
        error("Missing ')'");
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

int validmod(){
    char **mods = modifiers;
    char *p = token;
    while(*mods){
        if(strcmp(*mods++, p) == 0)
            return 1;
    }
    return 0;
}

int validtype(){
    char **type = types;
    char *p = token;
    while(*type){
        if(strcmp(*type++, p) == 0)
            return 1;
    }
    return 0;
}