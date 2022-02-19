/**
 *
 * Exercise 5.7 - Readlines
 *
 * Rewrite readlines to store lines in an array 
 * supplied by main, rather than calling alloc to maintain storage.
 *
 **/

#include<stdio.h>
#include<string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSTOR 5000
#define ALLOCSIZE 10000

int readlines(char *[], char *, int);
void writelines(char *[], int);
void qsort(char *[], int ,int);
int mgetline(char *,int);
void swap(char *[], int, int);
char *alloc(int);

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *lineptr[MAXLINES];
char linestor[MAXLINES];

main()
{
    int nlines;
    if((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0){
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
    }else{
        printf("Input too large!\n");
    }
}

int readlines(char *lineptr[], char *linestor, int maxlines){
    int len,nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines=0;

    while((len=mgetline(line,MAXLEN)) > 0)
        if(nlines >= maxlines || p+len > linestop)
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(p,line);
            lineptr[nlines++]=p;
            p+=len;
        }
    return nlines;
}

void writelines(char *lineptr[],int nlines){
    int i;
    for(i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void qsort(char *v[], int left, int right){
    int i, last;
    if(left >= right)
        return;
    swap(v, left ,(left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j){
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

char *alloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp -n;
    }else{
        return 0;
    }
}

int mgetline(char *s, int lim){
    int c;
    char *t = s;
    while(--lim && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if(c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}