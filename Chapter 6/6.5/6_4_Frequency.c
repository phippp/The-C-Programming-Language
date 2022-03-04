/**
 *
 * Exercise 6.4 - Frequency
 *
 * Write a program that prints the distinct words in its input sorted into
 * decreasing order of frequency of occurrence. Precede each word by its count.
 *
 **/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#define MAXWORD 100
#define BUFSIZE 100

struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
struct nnode{
    int count;
    struct list *list;
    struct nnode *left;
    struct nnode *right;
};
struct list{
    char *word;
    struct list *next;
};
char buffer[BUFSIZE];
int bufferloc = 0;

int getch();
void ungetch(int);
int isword(char *);
int getword(char *, int);
int charcmp(char *, char *);
struct tnode *talloc();
struct nnode *nalloc();
struct list *lalloc();
char *mystrdup(char *s);
struct tnode *addnode(struct tnode *, char *);
struct nnode *addnnode(struct nnode *, int, char *);
struct list *addlist(struct list *, char *);
void print_list(struct list *list);
struct nnode *traverse(struct tnode *, struct nnode *);
void print_tree(struct nnode *);

main(int argc, char *args[])
{
    struct tnode *root = NULL;
    struct nnode *node = NULL;
    char word[MAXWORD];
    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){
            root = addnode(root, word);
        }
    }
    node = traverse(root, node);
    print_tree(node);
}

struct tnode *talloc(){
    struct tnode *p = (struct tnode *) malloc(sizeof(struct tnode));
    return p;
}

struct list *lalloc(){
    struct list *p = (struct list *) malloc(sizeof(struct list));
    p->next = NULL;
    return p;
}

struct nnode *nalloc(){
    struct nnode *p = (struct nnode *) malloc(sizeof(struct nnode));
    p->list = NULL;
    return p;
}

char *mystrdup(char *s){
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if(p != NULL)
        strcpy(p, s);
    return p;
}

struct tnode *addnode(struct tnode *root, char *word){
    int c;
    if(root == NULL){
        root = talloc();
        root->word = mystrdup(word);
        root->count = 1;
        root->left = root->right = NULL;
    } else if((c = charcmp(word, root->word)) == 0){
        root->count++;
    } else if(c < 0){
        root->left = addnode(root->left, word);
    } else {
        root->right = addnode(root->right, word);
    }
    return root;
}

struct nnode *addnnode(struct nnode *node, int c, char *word){
    int i;
    if(node == NULL){
        node = nalloc();
        node->count = c;
        node->list = addlist(node->list, word);
        node->left = node->right = NULL;
    } else if((i = (node->count - c)) == 0){
        node->list = addlist(node->list, word);
    }else if(i > 0){
        node->left = addnnode(node->left, c, word);
    } else {
        node->right = addnnode(node->right, c, word);
    }
    return node;
}

struct list *addlist(struct list *p, char *word){
    if(p == NULL){
        p = lalloc();
        p->word = mystrdup(word);
    } else {
        p->next = addlist(p->next, word);
    }
    return p;
}

void print_tree(struct nnode *node){
    if(node != NULL){
        print_tree(node->left);
        printf("%4d -> ", node->count);
        print_list(node->list);
        print_tree(node->right);
    }
}

void print_list(struct list *list){
    printf("[%s", list->word);
    list = list->next;
    while(list != NULL){
        printf(", %s", list->word);
        list = list->next;
    }
    printf("]\n");
}

struct nnode *traverse(struct tnode *p, struct nnode *q){
    if(p != NULL){
        q = traverse(p->left, q);
        q = addnnode(q, p->count, p->word);
        q = traverse(p->right, q);
    }
    return q;
}

int getword(char *word, int lim){
    int c, d;
    char *w = word;
    while(isspace(c = getch()) || c == '_' || c == '/' || c == '#' || c == '*' || c == '"')
        ;
    if(c != EOF){
        *w++ = c;
    }
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for( ; --lim > 0; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

int charcmp(char *s1, char *s2){
    for(;tolower(*s1) == tolower(*s2); s1++, s2++)
        if(*s1 == '\0')
            return 0;
    return tolower(*s1) - tolower(*s2);
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