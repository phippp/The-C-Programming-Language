/**
 *
 * Exercise 6.1 - Getword
 *
 * Our version of getword does not properly handle underscores, 
 * string constants, comments, or preprocessor control lines. Write a better version.
 *
 **/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 100
#define NKEYS (sizeof(keytab) / sizeof(struct key))

/**
 * Whilst not technically necessary to add the braces because of the structures simplicity,
 * I personally think it looks clearer this way. 
 */

struct key {
    char *word;
    int count;
} keytab[] = {
    {"auto", 0 }, {"break", 0 }, {"case", 0 }, {"char", 0 }, {"const", 0 }, {"continue", 0 },
    {"default", 0}, {"do", 0 }, {"double", 0 }, {"else", 0 }, {"enum", 0 }, {"extern", 0 },
    {"float", 0}, {"for", 0 }, {"goto", 0 }, {"if", 0 }, {"int", 0 }, {"long", 0 }, {"register", 0},
    {"return", 0 }, {"short", 0 }, {"signed", 0 }, {"sizeof", 0 }, {"static", 0 }, {"struct", 0 },
    {"switch", 0 }, {"typedef", 0 }, {"union", 0 }, {"unsigned", 0 },  {"void", 0 },
    {"volatite", 0 }, {"while", 0 }
};
char buffer[BUFSIZE];
int bufferloc = 0;

int getword(char *, int);
int binsearch(char *, struct key *, int);
int getch();
void ungetch(int);

main()
{
    int n;
    char word[MAXWORD];
    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0]) && (n = binsearch(word, keytab, NKEYS)) >= 0){
            keytab[n].count++;
        }
    }
    for(n = 0; n < NKEYS; n++){
        if(keytab[n].count){
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
}

int binsearch(char *word, struct key keytab[], int n){
    int cond;
    int low, high, mid;

    low = 0;
    high = n -1;
    while (low <= high) {
        mid = (low+high) /2;
        if ((cond = strcmp(word, keytab[mid].word)) < 0 )
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int getword(char *word, int lim){
    int c, d;
    char *w = word;
    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;
    if(!isalpha(c)){
        if(c == '\"'){
            while((c = getch()) != '\"')
                ;
        } else if(c == '#'){
            while((c = getch()) != '\n')
                ;
        } else if(c == '/'){
            if((c = getch()) == '/'){
                while((c = getch()) != '\n')
                ;
            }else if(c == '*'){
                while((d = getch()) != '/' && c != '*')
                    c = d;
            }else{
                ungetch(c);
            }
        }else{
            while((c = getch()) != EOF && !isspace(c))
                ;
        }
        if(c != '\"' && c != '\n' && c != '/')
            ungetch(c);
        *w = '\0';
        return c;
    }
    for( ; --lim; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            if(!isspace(*w)){
                return *w;
            } else {
                break;
            }
        }
    }
    *w = '\0';
    return word[0];
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