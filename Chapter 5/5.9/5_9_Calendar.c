/**
 *
 * Exercise 5.9 - Calendar
 * 
 * Rewrite the routines day_of_year and month_day 
 * with pointers instead of indexing.
 * 
 **/

#include<stdio.h>

static char daytab[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year,int month,int day);
void month_day(int year,int yearday, int *month, int *day);

main()
{
    int yearday, month, day;
    yearday = day_of_year(1988, 2, 29);
    printf("%d\n", yearday);
    // 89
    yearday = day_of_year(2020, 2, 31);
    printf("%d\n", yearday);
    // -1
    month_day(1988,60, &month, &day);
    printf("Month: %d, Day: %d\n", month, day);
    // 2, 29
    month_day(1999,366, &month, &day);
    printf("Month: %d, Day: %d\n", month, day);
    // -1, -1
}

int day_of_year(int year, int month, int day){
    char *i; 
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(year < 1 || month < 1 || month > 12 || day < 1 || day > *(*daytab + (13 * leap) + month))
        return -1;
    for(i = *daytab + (13 * leap) + 1; i < *daytab + (13 * leap) + month + 1; i++)
        day += *i;
    return day;
}

void month_day(int year, int yearday, int *month, int *day){
    char *i;
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(year < 1 || yearday < 1 || yearday > (leap ? 366 : 365)){
        *month = -1;
        *day = -1;
        return;
    }
    for(i = *daytab + (13 * leap) + 1; yearday > *i; i++)
        yearday -= *i;
    *month = i - (*daytab + (13 * leap));
    *day = yearday;
}