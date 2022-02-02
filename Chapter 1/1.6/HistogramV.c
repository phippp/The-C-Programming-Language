#include <stdio.h>

#define MAXWORDS 30

main()
{
    int c, i, j, max, word;
    int words[MAXWORDS];

    word = max = 0;

    for(i = 0; i < MAXWORDS; i++)
        words[i] = 0;

    //Exercise 1.13 alternative
    while((c = getchar()) != EOF && word < MAXWORDS)
    {
        if(c == ' ' || c =='\n' || c == '\t')
            word++;
        else
            words[word]++;
    }

    for(i = 0; i <= word; i++)
        max = (words[i] > max) ? words[i] : max;

    for(i = max; i > 0; i--){
        for(j = 0; j <= word; j++){
            if(i > words[j])
                putchar(' ');
            else
                putchar('*');
        }
        putchar('\n');
    }
    

}