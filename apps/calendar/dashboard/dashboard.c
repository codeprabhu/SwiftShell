#include <stdio.h>
#include <time.h>

#include "dashboard.h"

static void clearScreen()
{
    printf("\033[2J");
    printf("\033[H");
}

static int isLeapYear(int year)
{
    if(year % 400 == 0)
        return 1;

    if(year % 100 == 0)
        return 0;

    return year % 4 == 0;
}

static int daysInMonth(int month, int year)
{
    switch(month)
    {
        case 0: return 31;
        case 1: return isLeapYear(year) ? 29 : 28;
        case 2: return 31;
        case 3: return 30;
        case 4: return 31;
        case 5: return 30;
        case 6: return 31;
        case 7: return 31;
        case 8: return 30;
        case 9: return 31;
        case 10:return 30;
        case 11:return 31;
    }

    return 30;
}

void renderCalendar(struct tm* current)
{
    clearScreen();

    char monthYear[64];

    strftime(
        monthYear,
        sizeof(monthYear),
        "%B %Y",
        current
    );

    printf("=====================================================\n");
    printf("                 SwiftCalendar\n");
    printf("=====================================================\n\n");

    printf("                  %s\n\n", monthYear);

    printf(" Su Mo Tu We Th Fr Sa\n\n");

    struct tm first = *current;

    first.tm_mday = 1;

    mktime(&first);

    int firstDay = first.tm_wday;

    int days =
        daysInMonth(
            current->tm_mon,
            current->tm_year + 1900
        );

    time_t now = time(NULL);
    struct tm today = *localtime(&now);

    for(int i = 0; i < firstDay; i++)
        printf("   ");

    for(int day = 1; day <= days; day++)
    {
        if(day == today.tm_mday &&
           current->tm_mon == today.tm_mon &&
           current->tm_year == today.tm_year)
        {
            printf("[%2d]", day);
        }
        else
        {
            printf("%3d", day);
        }

        if((firstDay + day) % 7 == 0)
            printf("\n");
    }

    printf("\n\n");

    printf("=====================================================\n");
    printf("[P] Previous Month\n");
    printf("[N] Next Month\n");
    printf("[Q] Quit\n");
    printf("=====================================================\n");
}