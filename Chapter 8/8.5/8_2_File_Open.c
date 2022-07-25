/**
 *
 * Exercise 8.2 - File Open
 *
 * Rewrite fopen and _fillbuf with fields instead of explicit 
 * bit operations. Compare code size and execution speed.
 *
 **/

/**
 * Field based approach is time consuming as we would have to check if each field 
 * is set or not while finding a free slot. Using Bit manipulation, we just have to 
 * compare the particular flag bit to zero.
 */

#include <fcntl.h>
#include <stdlib.h>

#define BUFSIZE 1000
#define PERMS 0666
#define MAX_OPEN 20
#define EOF (-1)
#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

#define getcx(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define getchar() getc(stdin)
#define putchar(x) putc(x, stdout)
#define getc(p) (--(p)->cnt >= 0 ? (unsigned char)*(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))

enum flags { _READ = 01, _WRITE = 02, _UNBUF = 04, _EOF = 010, _ERR = 020 };

typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	int flag;
	int fd;
} FILE;

FILE _iob[MAX_OPEN] = { { 0, (char *)0, (char *)0, _READ, 0 },
			            { 0, (char *)0, (char *)0, _WRITE, 1 },
			            { 0, (char *)0, (char *)0, _WRITE | _UNBUF, 2 } };

int _fillbuf(FILE *);
FILE *fopen(char *, char *);

main(int argc, char **args)
{
	FILE *file;
    char buf[1];

	while (--argc > 0)
		if ((file = fopen(*++args, "r")) == NULL)
			return 1;
		else
			while ((buf[0] = getc(file)) != EOF)
				write(1, buf, 1);
}

int _fillbuf(FILE *fp){
    int bufsize;

	if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;
	if (fp->base == NULL)
		if ((fp->base = (char *)malloc(bufsize)) == NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flag |= _EOF;
		if (fp->cnt == -2)
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char)*fp->ptr++;
}

FILE *fopen(char *name, char *mode){
    int fd;
	FILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + MAX_OPEN; fp++)
		if ((fp->flag & (_READ | _WRITE)) == 0)
			break;
	if (fp >= _iob + MAX_OPEN)
		return NULL;

	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);
	if (fd == -1)
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ? _READ : _WRITE;
	return fp;
}