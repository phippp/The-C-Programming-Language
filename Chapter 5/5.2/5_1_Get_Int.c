/**
 *
 * Exercise 5.1 - Get Int
 * 
 * As written, getint treats a + or - not followed by a digit as a 
 * valid representation of zero. Fix it to push such a character back on the input.
 * 
 **/

#include<stdio.h>
#include<ctype.h>

#define BUFSIZE 100
#define MAXNUMS 100

int getch(void);
void ungetch(int);
int getint(int *pointer);

char buffer[BUFSIZE];
int bufferloc = 0;

main()
{
    int n, val, array[MAXNUMS];
    n = 0;
    while(n < MAXNUMS && (val = getint(array + n)) != EOF){
        printf("array[%d] = %d, \tValue returned: %d (%s)\n", n, *(array + n), val, val != 0 ? "number" : "NaN");
        if(val)
            n++;
    }
}

int getint(int *pointer){
	int c, sign;
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
	*pointer *= sign;
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