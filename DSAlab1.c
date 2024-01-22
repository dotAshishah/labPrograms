#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int i;
#define NUM_DAYS_IN_WEEK 7
#define MAX_STRING_LENGTH 50

typedef struct {
    char *acDayName;
    int iDate;
    char *acActivity;
} DAYTYPE;

void FreeCal(DAYTYPE *);
void DispCal(DAYTYPE *);
void ReadCal(DAYTYPE *);
DAYTYPE *CreateCal();

int main() {
    DAYTYPE *WeeklyCalendar = CreateCal();

    ReadCal(WeeklyCalendar);
    DispCal(WeeklyCalendar);
    FreeCal(WeeklyCalendar);

    return 0;
}

DAYTYPE *CreateCal() {
    DAYTYPE *calendar = (DAYTYPE *)malloc(NUM_DAYS_IN_WEEK * sizeof(DAYTYPE));

    for (i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        calendar[i].acDayName = NULL;
        calendar[i].iDate = 0;
        calendar[i].acActivity = NULL;
    }

    return calendar;
}

void ReadCal(DAYTYPE *calendar) {
    char choice;
    for (i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        printf("Do you want to enter details for day %d [Y/N]: ", i + 1);
        scanf(" %c", &choice);
        getchar(); // consume newline

        if (tolower(choice) == 'n') {
            continue;
        }

        printf("Day Name: ");
        char nameBuffer[MAX_STRING_LENGTH];
        scanf("%s", nameBuffer);
        calendar[i].acDayName = strdup(nameBuffer);

        printf("Date: ");
        scanf("%d", &calendar[i].iDate);

        printf("Activity: ");
        char activityBuffer[MAX_STRING_LENGTH];
        scanf("%s", activityBuffer);
        calendar[i].acActivity = strdup(activityBuffer);

        printf("\n");
    }
}

void DispCal(DAYTYPE *calendar) {
    printf("\nWeek's Activity Details:\n");
    for (i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        printf("\nDay %d:\n", i + 1);
        if (calendar[i].iDate == 0) {
            printf("No Activity\n");
            continue;
        }

        printf("Day Name: %s\n", calendar[i].acDayName);
        printf("Date: %d\n", calendar[i].iDate);
        printf("Activity: %s\n", calendar[i].acActivity);
    }
}

void FreeCal(DAYTYPE *calendar) {
    for (i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        free(calendar[i].acDayName);
        free(calendar[i].acActivity);
    }
    free(calendar);
}
