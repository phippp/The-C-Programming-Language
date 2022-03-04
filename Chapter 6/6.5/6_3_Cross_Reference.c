/**
 *
 * Exercise 6.3 - Cross Referencer
 *
 * Write a cross-referencer that prints a list of all words in a 
 * document, and for each word, a list of the line numbers
 * on which it occurs. Remove noise words like "the" and "and" so on.
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
    struct list *lines;
    struct tnode *left;
    struct tnode *right;
};
struct list{
    int num;
    struct list *next;
};
char *ignore[] = { "the", "and", "i", "am" ,"is", "a", "an",
                    "so", "as", "at", "because", "she", "he",
                    "you", "me", "but", "are", "by", "do"};
char buffer[BUFSIZE];
int bufferloc = 0;

int getch();
void ungetch(int);
int isword(char *);
int getword(char *, int, int *);
int charcmp(char *, char *);
struct tnode *talloc();
struct list *lalloc();
char *mystrdup(char *s);
struct tnode *addnode(struct tnode *, char *, int);
struct list *addlist(struct list *, int);
void print_tree(struct tnode *);
void print_list(struct list *);

main(int argc, char *args[])
{
    struct tnode *root = NULL;
    int line = 0;
    char word[MAXWORD];
    while(getword(word, MAXWORD, &line) != EOF){
        if(isalpha(word[0]) && isword(word)){
            root = addnode(root, word, line);
        }
    }
    print_tree(root);
}

struct tnode *talloc(){
    struct tnode *p = (struct tnode *) malloc(sizeof(struct tnode));
    p->lines = NULL;
    return p;
}

struct list *lalloc(){
    struct list *p = (struct list *) malloc(sizeof(struct list));
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

int isword(char *word){
    int c;
    char **i = ignore;
    int len = sizeof(ignore) /sizeof(ignore[0]);
    for(c = 0; c < len; c++)
        if(charcmp(i[c], word) == 0)
            return 0;
    return 1;
}

struct list *addlist(struct list *l, int line){
    if(l == NULL){
        l = lalloc();
        l->num = line;
        l->next = NULL;
    } else{
        l->next = addlist(l->next, line);
    }
    return l;
}

struct tnode *addnode(struct tnode *root, char *word, int line){
    int c;
    if(root == NULL){
        root = talloc();
        root->lines = addlist(root->lines, line);
        root->word = mystrdup(word);
        root->count = 1;
        root->left = root->right = NULL;
    } else if((c = charcmp(word, root->word)) == 0){
        root->lines = addlist(root->lines, line);
        root->count++;
    } else if(c < 0){
        root->left = addnode(root->left, word, line);
    } else {
        root->right = addnode(root->right, word, line);
    }
    return root;
}

void print_tree(struct tnode *node){
    if(node != NULL){
        print_tree(node->left);
        printf("%4d occurances of '%s':\n", node->count, node->word);
        print_list(node->lines);
        printf("\n");
        print_tree(node->right);
    }
}

void print_list(struct list *list){
    printf("\t seen on lines: [%d", list->num);
    list = list->next;
    while(list != NULL){
        printf(", %d", list->num);
        list = list->next;
    }
    printf("]\n");
}

int getword(char *word, int lim, int *line){
    int c, d;
    char *w = word;
    while(isspace(c = getch()))
        if(c == '\n')
            (*line)++;
    if(c != EOF)
        *w++ = c;
    while(!(isalnum(c) || c == EOF)){
        if(c == '\n')
            (*line)++;
        c = getch();
    }
    if(c == EOF){
        ungetch(c);
        *w = '\0';
        return c;
    }
    for( ; --lim; w++){
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