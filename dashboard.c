#include <stdio.h>
#include "dashboard.h"
#include "passwordmanager.h"
#include "securerecords.h"
#include "activity.h"
#include "logout.h"
#include "accountlog.h"
#include "backup.h"
#include "restore.h"

void dashboard(const char username[])
{
    int choice;

    printf("\n===== SecureVault Dashboard =====\n");

    while (1)
    {
        printf("\n===== SecureVault Dashboard =====\n");
        printf("1. Password Manager\n");
        printf("2. Secure Records\n");
        printf("3. Backup Data\n");
        printf("4. Restore Data\n");
        printf("5. Logout\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            activityLog(username, "OPENED PASSWORD MANAGER");
            passwordManager(username);
        }
        else if (choice == 2)
        {
            activityLog(username, "OPENED SECURE RECORDS");
            secureRecords(username);
        }
        else if (choice == 3)
        {
            activityLog(username, "BACKUP DATA");
            backupData();
        }
        else if (choice == 4)
        {
            activityLog(username, "RESTORE DATA");
            restoreData();
        }
        else if (choice == 5)
        {
            logout(username);
            break;
        }
        else
        {
            activityLog(username, "ENTERED INVALID DASHBOARD OPTION");
            printf("\nInvalid choice!\n");
        }
    }
}
