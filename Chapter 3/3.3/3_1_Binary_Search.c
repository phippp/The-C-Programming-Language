/**
 *
 * Exercise 3.1 - Binary Search
 * 
 * Binsearch function, by writing minimum tests 
 * inside the loop ( at the cost of more outside)
 * 
 **/

#include <stdio.h>

int binsearch(int find, int list[], int size);

main()
{
    int array[] = {2, 4, 6, 7, 9, 29, 45, 46, 49, 50, 51};
    printf("%d was at index %d", 7, binsearch(7, array, 10));
}

int binsearch(int find, int list[], int size){
    int low, mid, high;
    low = 0;
    high = size - 1;
    mid = (low + high) / 2;
    while(low < high && find != list[mid]){
        if(find > list[mid])
            low = mid + 1;
        else
            high = mid - 1;
        mid = (low + high) /2;
    }
    return (find == list[mid]) ? mid : -1;
}