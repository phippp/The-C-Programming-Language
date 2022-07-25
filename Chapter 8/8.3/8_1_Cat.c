/**
 *
 * Exercise 8.1 - Cat
 *
 * Rewrite the program cat from Chapter 7 using read, write,
 * open and close instead of their standard library equivalents.
 *
 **/

#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE 1000

void filecopy(int, int);

main(int argc, char **args)
{
    int file;

    if(argc == 1) {
        filecopy(0, 1);
    } else {
        while(--argc){
            if((file = open(*(++args), O_RDONLY, 0)) == -1){
                printf("Can't open %s\n", *args);
                continue;
            } else {
                filecopy(file, 1);
                close(file);
            }
        }
    }
}

void filecopy(int in, int out){
    int n;
    char buf[BUFSIZE];

    while((n = read(in, buf, BUFSIZE)) > 0 )
        write(out, buf, n);
}