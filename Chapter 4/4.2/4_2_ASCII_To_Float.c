/**
 *
 * Exercise 4.2 - ASCII To Float (atof)
 * 
 * Extend atof to handle scientific notation of the form 123.45e-6 where a 
 * floating-point number may be followed by e or E and an optionally signed exponent.
 * 
 **/

#include <stdio.h>
#include <ctype.h>

double atof(char str[]);
int power(int n, int e);

main()
{
    char str[] = "-45.6756e+2";
    printf("%f", atof(str));
}

double atof(char str[]){
    double val, pow;
    int sign, i, esign, exp;      
        
    for(i = 0; isspace(str[i]); i++)
        ;
    sign = (str[i] == '-') ? -1 : 1;
    if(str[i] =='+' || str[i] == '-')
        i++;
    for(val = 0.0; isdigit(str[i]); i++)
        val = 10.0 * val + (str[i] - '0');
    if(str[i]=='.')
        i++;
    for(pow = 1.0; isdigit(str[i]); i++){
        val = 10.0 * val + (str[i] - '0');
        pow *= 10.0;
    }
    if(str[i]=='e' || str[i] =='E')
        i++;
    if(str[i]=='+' || str[i] =='-')
        esign = str[i++];
    for(exp = 0; isdigit(str[i]); i++)
        exp = 10.0 * exp + (str[i] - '0');
    
    if( esign == '-')
        return sign * (val / pow) / power(10, exp);
    else
        return sign * (val / pow) * power(10, exp);
}

int power(int n, int e){
    int power = 1;
    while(e--)
        power *= n;
    return power;
}