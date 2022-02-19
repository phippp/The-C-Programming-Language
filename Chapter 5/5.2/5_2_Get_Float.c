/**
 *
 * Exercise 5.2 - Get Float
 * 
 * Write a program to get next float from input to *pn
 * 
 **/

#include<stdio.h>
#include<ctype.h>

#define BUFSIZE 100
#define MAXNUMS 100

int getch(void);
void ungetch(int);
int getfloat(float *pointer);

char buffer[BUFSIZE];
int bufferloc = 0;

main()
{
    int n;
    float val, array[MAXNUMS];
    n = 0;
    while(n < MAXNUMS && (val = getfloat(array + n)) != EOF){
        printf("array[%d] = %.3f, \tValue returned: %.3f (%s)\n", n, *(array + n), val, val != 0 ? "number" : "NaN");
        if(val)
            n++;
    }
}

int getfloat(float *pointer){
	int c, sign;
    float exp;
	while(isspace(c = getch()))
        ;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-') {
		c = getch();
		if(!isdigit(c)){
			ungetch(sign == -1 ? '-' : '+');
			return 0;
		}
	}	
	for(*pointer = 0; isdigit(c); c = getch())
		*pointer = *pointer * 10 + (c - '0');
    if(c == '.')
        c = getchar();
    for(exp = 1.0; isdigit(c); c = getch()){
        *pointer = *pointer * 10 + (c - '0');
        exp *= 10;
    }
	*pointer *= (sign / exp);
	if(c != EOF)
		ungetch(c);
	return c;
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