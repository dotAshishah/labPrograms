#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_DAYS_IN_WEEK 7

// Global variable Declaration
int i;

// Structure to represent a day
typedef struct
{
    char *acDayName;    // Dynamically allocated string for the day name
    int iDate;           // Date of the day
    char *acActivity;    // Dynamically allocated string for the activity description
} DAYTYPE;

// Prototypes
void FreeCal(DAYTYPE *);
void DispCal(DAYTYPE *);
void ReadCal(DAYTYPE *);
DAYTYPE *CreateCal();

// Main function
int main()
{
    // Create the calendar
    DAYTYPE *weeklyCalendar = CreateCal();

    // Read data from the keyboard
    ReadCal(weeklyCalendar);

    // Display the week's activity details
    DispCal(weeklyCalendar);

    // Free allocated memory
    FreeCal(weeklyCalendar);

    return 0;
}

// Create calendar function definition
DAYTYPE *CreateCal()
{
    DAYTYPE *calendar = (DAYTYPE *)malloc(NUM_DAYS_IN_WEEK * sizeof(DAYTYPE));

    for (i = 0; i < NUM_DAYS_IN_WEEK; i++)
    {
        calendar[i].acDayName = NULL;
        calendar[i].iDate = 0;
        calendar[i].acActivity = NULL;
    }

    return calendar;
}

// Read Calendar function definition
void ReadCal(DAYTYPE *calendar)
{
    char Choice;
    for (i = 0; i < NUM_DAYS_IN_WEEK; i++)
    {
        printf("Do you want to enter details for day %d [Y/N]: ", i + 1);
        scanf(" %c", &Choice);
        getchar();

        if (tolower(Choice) == 'n')
            continue;

        printf("Day Name: ");
        char nameBuffer[50];
        scanf("%s", nameBuffer);
        calendar[i].acDayName = strdup(nameBuffer); // Dynamically allocate and copy the string

        printf("Date: ");
        scanf("%d", &calendar[i].iDate);

        printf("Activity: ");
        char activityBuffer[100];
        scanf(" %[^\n]", activityBuffer); // Read the entire line, including spaces
        calendar[i].acActivity = strdup(activityBuffer);

        printf("\n");
        getchar(); // Remove trailing enter character in input buffer
    }
}

// Display Calendar function definition
void DispCal(DAYTYPE *calendar)
{
    printf("\nWeek's Activity Details:\n");
    for (i = 0; i < NUM_DAYS_IN_WEEK; i++)
    {
        printf("Day %d:\n", i + 1);
        if (calendar[i].iDate == 0)
        {
            printf("No Activity\n\n");
            continue;
        }

        printf("  Day Name: %s\n", calendar[i].acDayName);
        printf("  Date: %d\n", calendar[i].iDate);
        printf("  Activity: %s\n\n", calendar[i].acActivity);
    }
}

// Free Calendar function definition
void FreeCal(DAYTYPE *calendar)
{
    for (i = 0; i < NUM_DAYS_IN_WEEK; i++)
    {
        free(calendar[i].acDayName);
        free(calendar[i].acActivity);
    }
    free(calendar);
}
