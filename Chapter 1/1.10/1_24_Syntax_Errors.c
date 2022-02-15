/**
 * Exercise 1.24 - Syntax Errors
 *
 * Program to check rudimentary syntax errors like un-match braces,
 * brackets or parenthesis.
 * 
 **/

#include <stdio.h>

#define MAXCOMMENT 100

int comment();
int quote(int n);
int getopenbrace(int n);

main()
{
    int c, stuck, i;
    stuck = i = 0;
    char braces[MAXCOMMENT];
    while((c = getchar()) != EOF){
        if(c == '{' || c == '[' || c == '('){
            braces[i++] = c;
        } else if(c == '}' || c == ']' || c == ')'){
            if(braces[i - 1] == getopenbrace(c))
                braces[--i] = '\0';
            else
                break;
        } else if(c == '\'' || c == '"' ){
            stuck = quote(c);
        } else if(c == '/'){
            if((c = getchar()) == '*')
                stuck = comment();
        }
        if(stuck > 0) break;
    }
    if(i > 0) printf("Brace '%c' does not close '%c'", c, braces[i-1]);
    if(stuck > 0) printf("Comment/ Quote was too long to parse");
}

int getopenbrace(int c){
    if(c == '}') return '{';
    if(c == ']') return '[';
    else return '(';
}

int quote(int c){
    int d, counter = 0;
    printf("%s", "Quote");
    while((d = getchar()) != c && counter++ < MAXCOMMENT){
        if(d == '\\')
            getchar();
    }
    return d != c ? 1 : 0;
}

int comment(){
    int c, d, counter = 0;
    printf("%s\n", "Comment");
    c = getchar();
    while(d = getchar(), !(c == '*' && d == '/') && counter++ < MAXCOMMENT){
        c = d;
    }
    return !(c == '*' && d == '/') ? 1 : 0;
}