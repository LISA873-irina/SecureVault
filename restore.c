#include <stdio.h>
#include "restore.h"

void restoreData(void)
{
    FILE *source;
    FILE *destination;
    int ch;
    const char *backupFiles[] = {
        "backup_users.dat",
        "backup_passwords.dat",
        "backup_secure_records.dat",
        "backup_account_log.dat",
        "backup_activity_log.dat"
    };
    const char *files[] = {
        "users.dat",
        "passwords.dat",
        "secure_records.dat",
        "account_log.dat",
        "activity_log.dat"
    };
    int i;
    int restored = 0;

    for (i = 0; i < 5; i++)
    {
        source = fopen(backupFiles[i], "rb");

        if (source == NULL)
        {
            continue;
        }

        destination = fopen(files[i], "wb");

        if (destination == NULL)
        {
            fclose(source);
            continue;
        }

        while ((ch = fgetc(source)) != EOF)
        {
            fputc(ch, destination);
        }

        fclose(source);
        fclose(destination);
        restored = 1;
    }

    if (restored)
        printf("\nRestore completed successfully!\n");
    else
        printf("\nNo backup data was found to restore.\n");
}
