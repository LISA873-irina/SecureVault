#include <stdio.h>
#include "register.h"
#include "login.h"

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== SecureVault =====\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            registerUser();
        }
        else if (choice == 2)
        {
            loginUser();
        }
        else if (choice == 3)
        {
            printf("\nExiting... Goodbye!\n");
            break;
        }
        else
        {
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}