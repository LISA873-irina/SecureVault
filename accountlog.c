#include <stdio.h>
#include <time.h>
#include "accountlog.h"

void accountLog(const char username[], const char action[])
{
    FILE *fp = fopen("account_log.dat", "a");
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

    fprintf(fp, "[%s] Username: %s | Action: %s\n",
            timeText, username, action);

    fclose(fp);
}
