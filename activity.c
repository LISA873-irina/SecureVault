#include <stdio.h>
#include <time.h>
#include "activity.h"

void activityLog(const char username[], const char activity[])
{
    FILE *fp = fopen("activity_log.dat", "a");
    time_t now;
    struct tm *timeInfo;
    char timeText[30];

    if (fp == NULL)
    {
        return;
    }

    now = time(NULL);
    timeInfo = localtime(&now);

    if (timeInfo != NULL)
    {
        strftime(timeText, sizeof(timeText), "%Y-%m-%d %H:%M:%S", timeInfo);
    }
    else
    {
        snprintf(timeText, sizeof(timeText), "UNKNOWN-TIME");
    }

    fprintf(fp, "[%s] Username: %s | Activity: %s\n",
            timeText, username, activity);

    fclose(fp);
}
