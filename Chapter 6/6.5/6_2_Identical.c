/**
 *
 * Exercise 6.2 - Identical
 *
 * Write a program that reads a C program and prints in alphabetical order 
 * each group of variable names that are identical in the first 6 characters, 
 * but different somewhere thereafter. Don’t count words within strings 
 * and comments. Make 6 a parameter that can be set from the command line.
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#define MAXWORD 100
#define BUFSIZE 100
#define DEFAULT_LENGTH 6

/**
 * This implementation makes it so that each node only stores the comparable 
 * parts of the word, a linked list then is used to store the words which are
 * actually similar. 
 */
struct tnode{
    char *comparable;
    int count;
    struct simword *list;
    struct tnode *left;
    struct tnode *right;
};
struct simword{
    char *word;
    struct simword *next;
};
char *ignore[] = {"include", "main", "return", "int", "char", "void", "\0"};
char buffer[BUFSIZE];
int bufferloc = 0;
int check = DEFAULT_LENGTH;

int getch();
int is_var(char *);
void ungetch(int);
int getword(char *, int);
struct tnode *talloc();
struct simword *walloc();
char *mystrdup(char *s);
struct tnode *addnode(struct tnode *, char *);
struct simword *addword(struct simword *, char *);
void print_tree(struct tnode *);
void print_list(struct simword *);

main(int argc, char *args[])
{
    struct tnode *root = NULL;
    char word[MAXWORD];
    if(--argc)
        check = atoi(*++args);
    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0]) && is_var(word)){
            root = addnode(root, word);
        }
    }
    print_tree(root);
}

struct tnode *talloc(){
    struct tnode *p = (struct tnode *) malloc(sizeof(struct tnode));
    p->list = NULL;
    return p;
}

struct simword *walloc(){
    struct simword *p = (struct simword *) malloc(sizeof(struct simword));
    p->next = NULL;
    return p;
}

char *mystrdup(char *s){
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if(p != NULL)
        strcpy(p, s);
    return p;
}

int is_var(char *word){
    int c;
    char **i = ignore;
    int len = sizeof(ignore) /sizeof(ignore[0]);
    for(c = 0; c < len; c++)
        if(strcmp(i[c], word) == 0)
            return 0;
    return 1;
}

struct simword *addword(struct simword *sim, char *word){
    if(sim == NULL){
        sim = walloc();
        sim->word = mystrdup(word);
        sim->next = NULL;
    } else if(strcmp(word, sim->word) != 0){
        sim->next = addword(sim->next, word);
    }
    return sim;
}

struct tnode *addnode(struct tnode *root, char *word){
    int c;
    char comp[MAXWORD];
    memcpy(comp, word, 6);
    comp[check] = '\0';
    if(root == NULL){
        root = talloc();
        root->list = addword(root->list, word);
        root->comparable = mystrdup(comp);
        root->count = 1;
        root->left = root->right = NULL;
    } else if((c = strcmp(comp, root->comparable)) == 0){
        root->list = addword(root->list, word);
        root->count++;
    } else if(c < 0){
        root->left = addnode(root->right, word);
    } else {
        root->right = addnode(root->right, word);
    }
    return root;
}

void print_tree(struct tnode *node){
    if(node != NULL){
        print_tree(node->left);
        printf("%4d variables started with '%s':\n", node->count, node->comparable);
        print_list(node->list);
        printf("\n");
        print_tree(node->right);
    }
}

void print_list(struct simword *list){
    while(list != NULL){
        printf("\t\t%s \n", list->word);
        list = list->next;
    }
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
                return *w = '\0';
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