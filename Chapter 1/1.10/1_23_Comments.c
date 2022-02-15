/**
 * Exercise 1.23 - Comments
 *
 * Program to remove comments from a C Program.
 * 
 **/

#include <stdio.h>

void read(int n);
void waitforend();
void quote(int n);

main()
{
    int c;
    while((c = getchar()) != EOF)
        read(c);
}

void read(int c){
    int d;
    if(c == '/'){
        if((d = getchar()) == '*'){
            waitforend();
        }else if (d == '/'){
            putchar(c);
            read(d);
        }else{
            putchar(c);
            putchar(d);
        }
    } else if(c == '\'' || c == '"'){
        quote(c);
    } else {
        putchar(c);
    }
}

void quote(int c){
    int d;
    putchar(c);
    while((d = getchar()) != c){
        putchar(d);
        if(d == '\\')
            putchar(getchar());
    }
    putchar(d);
}

void waitforend(){
    int c, d;
    c = getchar();
    while(d = getchar(), !(c == '*' && d == '/')){
        c = d;
    }
}