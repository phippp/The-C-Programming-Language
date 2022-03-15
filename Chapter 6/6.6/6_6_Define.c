/**
 *
 * Exercise 6.6 - Define
 *
 * Write a function undef that will remove a name and definition
 * from the table maintained by lookup and install.
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#define HASHSIZE 101
#define BUFSIZE 100
#define MAXWORD 100

struct nlist{
    char *name;
    char *def;
    struct nlist *next;
};
static struct nlist *hashtab[HASHSIZE];
char buffer[BUFSIZE];
int bufferloc = 0;

int getch();
void ungetch(int);

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *name, char *definition);
struct nlist *undef(char *name);
int getword(char *, int);
char *mystrdup(char *);

main()
{
    struct nlist *result;
    char word[MAXWORD], key[MAXWORD], value[MAXWORD];
    while(getword(word, MAXWORD) != EOF){
        if(strcmp(word, "#define") == 0){
            getword(key, MAXWORD);
            getword(value, MAXWORD);
            install(key, value);
            result = lookup(key);
            printf("%s -> %s\n", result->name, result->def);
        }
    }
}

unsigned hash(char *word){
    unsigned x;
    for(x = 0; *word != '\0'; word++){
        x = (x * 31) + *word;
    }
    return x % HASHSIZE;
}

struct nlist *lookup(char *s){
    struct nlist *p;
    for(p = hashtab[hash(s)]; p != NULL; p = p->next){
        if(strcmp(s, p->name) == 0){
            return p;
        }
    }
    return NULL;
}

struct nlist *install(char *name, char *definition){
    struct nlist *p;
    unsigned h;
    if((p = lookup(name)) == NULL){
        p = (struct nlist *) malloc(sizeof(struct nlist));
        if (p == NULL || (p->name = mystrdup(name)) == NULL)
            return NULL;
        h = hash(name);
        p->next = hashtab[h];
        hashtab[h] = p;
    } else {
        free((void *) p->def);
    }
    if ((p->def = mystrdup(definition)) == NULL)
        return NULL;
    return p;
}

struct nlist *undef(char *name){
    struct nlist *p = lookup(name);
    if(p == NULL)
        return NULL;
    
    if(p->next != NULL){
        p->next = p->next->next;
        p = p->next;
    }else {
        hashtab[hash(name)] = NULL;
        free((void *) p);
    }
}

char *mystrdup(char *s){
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if(p != NULL)
        strcpy(p, s);
    return p;
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

int getword(char *word, int lim){
    int c, d;
    char *w = word;
    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;
    if(!(isalnum(c) || c == '#' || c == '\'' || c == '\"')){
        if(c == '/'){
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
        if(c != '\n' && c != '/')
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