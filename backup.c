#include <stdio.h>
#include "backup.h"

void backupData(void)
{
    FILE *source;
    FILE *destination;
    int ch;
    const char *files[] = {
        "users.dat",
        "passwords.dat",
        "secure_records.dat",
        "account_log.dat",
        "activity_log.dat"
    };
    const char *backupFiles[] = {
        "backup_users.dat",
        "backup_passwords.dat",
        "backup_secure_records.dat",
        "backup_account_log.dat",
        "backup_activity_log.dat"
    };
    int i;
    int backedUp = 0;

    for (i = 0; i < 5; i++)
    {
        source = fopen(files[i], "rb");

        if (source == NULL)
        {
            continue;
        }

        destination = fopen(backupFiles[i], "wb");

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
        backedUp = 1;
    }

    if (backedUp)
        printf("\nBackup completed successfully!\n");
    else
        printf("\nNo data was available to back up.\n");
}
