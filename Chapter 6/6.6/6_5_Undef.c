/**
 *
 * Exercise 6.5 - Undef
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

struct nlist{
    char *name;
    char *def;
    struct nlist *next;
};
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *name, char *definition);
struct nlist *undef(char *name);
char *mystrdup(char *);

main()
{
    int i;
    struct nlist *p;
    char *keys[] = {"key1", "key2", "key3", "key4"};
    char *vals[] = {"value1", "value2", "value3", "value4"};
    for(i = 0; i < (sizeof(keys) / sizeof(keys[0])); i++){
        install(keys[i], vals[i]); 
    }
    undef("key");
    undef("key2");
    for(i = 0; i < (sizeof(keys) / sizeof(keys[0])); i++){
        if((p = lookup(keys[i])) == NULL){
            printf("[%s] was not found\n", keys[i]);
        } else {
            printf("%s -> %s\n", p->name, p->def);
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