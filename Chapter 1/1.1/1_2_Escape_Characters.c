/**
 *
 * Exercise 1.2 - Escape Characters.
 *
 * Program to test what characters can be escaped in printf();
 *
 **/

#include<stdio.h>

main()
{
    printf("a:\a"); /* valid */
    printf("b:\b"); /* valid */
    // printf("c:\c");
    // printf("d:\d");
    printf("e:\e"); /* valid */
    printf("f:\f"); /* valid */
    // printf("g:\g");
    // printf("h:\h");
    // printf("i:\i");
    // printf("j:\j");
    // printf("k:\k");
    // printf("l:\l");
    // printf("m:\m");
    printf("n:\n"); /* valid */
    // printf("o:\o");
    // printf("p:\p");
    // printf("q:\q");
    printf("r:\r"); /* valid */
    // printf("s:\s");
    printf("t:\t"); /* valid */
    printf("u:\u2603"); /* valid with unicode number */
    printf("v:\v"); /* valid */
    // printf("w:\w");
    printf("x:\xD"); /* valid with hexadecimal value */
    // printf("y:\y");
    // printf("z:\z");
    // printf("A:\A");
    // printf("B:\B");
    // printf("C:\C");
    // printf("D:\D");
    printf("E:\E"); /* valid */
    // printf("F:\F");
    // printf("G:\G");
    // printf("H:\H");
    // printf("I:\I");
    // printf("J:\J");
    // printf("K:\K");
    // printf("L:\L");
    // printf("M:\M");
    // printf("N:\N");
    // printf("O:\O");
    // printf("P:\P");
    // printf("Q:\Q");
    // printf("R:\R");
    // printf("S:\S");
    // printf("T:\R");
    printf("U:\U00002603"); /* valid with unicode number */
    // printf("V:\V");
    // printf("W:\W");
    // printf("X:\X");
    // printf("Y:\Y");
    // printf("Z:\Z");
    // printf("0:\0");
    printf("1:\1"); /* valid */
    printf("2:\2"); /* valid */
    printf("3:\3"); /* valid */
    printf("4:\4"); /* valid */
    printf("5:\5"); /* valid */
    printf("6:\6"); /* valid */
    printf("7:\7"); /* valid */
    // printf("8:\8");
    // printf("9:\9");
    // printf("~:\~");
    // printf("`:\`");
    // printf("!:\!");
    // printf("@:\@");
    // printf("#:\#");
    // printf("$:\$");
    printf("%:\%"); /* valid */
    // printf("^:\^");
    // printf("&:\&");
    // printf("*:\*");
    printf("(:\("); /* valid */
    // printf("):\)");
    // printf("_:\_");
    // printf("-:\-");
    // printf("+:\+");
    printf("{:\{"); /* valid */
    printf("[:\["); /* valid */
    // printf("}:\}");
    // printf("]:\]");
    // printf("|:\|");
    // printf("\:\\");
    printf("a:\a"); /* valid */
    // printf("::\:");
    // printf(";:\;");
    printf("\":\""); /* valid */
    printf("':\'"); /* valid */
    // printf("<:\<");
    // printf(",:\,");
    // printf(">:\>");
    // printf(".:\.");
    printf("?:\?"); /* valid */
    // printf("/:\/");
}
