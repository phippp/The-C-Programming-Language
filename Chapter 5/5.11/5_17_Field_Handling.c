/**
 *
 * Exercise 5.17 - Field Handling
 *
 * Add a field-searching capability, so sorting may bee done on fields 
 * within lines, each field sorted according to an independent set of options.
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMERIC 1
#define REVERSE 2
#define INSENSITIVE 4
#define DIRECTORY 8
#define MAXLINES 100
#define MAXLENGTH 1000
#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
static int option = 0;
static int start = 0;
static int end = 0;

void arguments(int, char *[]);
void substr(char *, char *, int, int);
int mgetline(char *, int);
int numcmp(char *, char *);
int charcmp(char *, char *);
int readlines(char *[], int);
void writelines(char *[], int, int);
char *alloc(int);
void swap(void *[], int, int);
void myqsort(void *[], int, int, int (*comp)(void *, void *));

main(int argc, char *args[])
{
    int nlines;
    int (*compare)(void *, void *);
    char *lineptr[MAXLINES];
    arguments(argc, args);
    compare = (option & NUMERIC) ? numcmp : charcmp;
    if((nlines = readlines(lineptr, MAXLINES)) > 0){
        myqsort((void **)lineptr, 0, nlines -1, compare);
        writelines(lineptr, nlines, option & REVERSE);
    }else{
        printf("input too big to sort \n");
    }
}

void arguments(int c, char *args[]){
    char *input;
    while(--c && *(input = *++args) == '-' || *input == '+'){
        if(*input == '-' && !isdigit(*(input + 1))){
            while(*++input){
                switch (*input){
                    case 'd':
                        option |= DIRECTORY;
                        break;
                    case 'r':
                        option |= REVERSE;
                        break;
                    case 'n':
                        option |= NUMERIC;
                        break;
                    case 'f':
                        option |= INSENSITIVE;
                        break;          
                    default:
                        printf("Invalid flag -%c\n", *input);
                        break;
                }
            }
        } else if(*input == '-'){
            end = atoi(input + 1);
        } else {
            start = atoi(input + 1);
        }
    }
    if(start > end){
        printf("ERROR: Start bigger than end\n");
        exit(1);
    }
}

void substr(char *in, char *out, int start, int end){
    int i;
    int length = strlen(in);
    int e = end ? end : length;
    if(start >= length || e > length){
        printf("ERROR: String too short [%d, %d]\n", start, e);
        exit(1);
    }
    for(i = 0; i < start; i++, in++)
        ;
    for(; i < e; i++)
        *out++ = *in++;
    *out = '\0';
}

int numcmp(char *s1, char *s2){
    char str[MAXLENGTH];
    double v1, v2;
    substr(s1, str, start, end);
    v1 = atof(str);
    substr(s2, str, start, end);
    v2 = atof(str);
    return (int)(v1 - v2);
}

int charcmp(char *s1, char *s2){
    int comp;
    char str1[MAXLENGTH], str2[MAXLENGTH];
    char *p1 = str1, *p2 = str2;
    int i = (option & INSENSITIVE);
    int d = (option & DIRECTORY);
    substr(s1, str1, start, end);
    substr(s2, str2, start, end);
    do{
        if(d){
            while(!isalnum(*p1) && *p1 != ' ' && *p1 != '\0')
                p1++;
            while(!isalnum(*p2) && *p2 != ' ' && *p2 != '\0')
                p2++;
        }
        comp = (i) ? tolower(*p1) == tolower(*p2) : *p1 == *p2;
        if(comp && *p1 == '\0')
            return 0;
    }while(*p1++ == *p2++);
    return *--p1 - *--p2;
}

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLENGTH];
    nlines = 0;

    while((len = mgetline(line, MAXLENGTH)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL){
            return -1;
        }else        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int reverse){
    int i;
    if(reverse){
        for(i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    } else {
        for(i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
    }
}

int mgetline(char *s, int lim){
    int c;
    char *t = s;
    while (--lim && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

char *alloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }
    return 0;
}

void myqsort(void *v[], int left, int right, int (*comp)(void *,void *)){
    int i, last;
    if(left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    myqsort(v, left, last-1, comp);
    myqsort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j){
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
