#include <stdio.h>
#include "logout.h"
#include "accountlog.h"
#include "activity.h"

void logout(const char username[])
{
    accountLog(username, "LOGOUT");
    activityLog(username, "LOGGED OUT");
    printf("\nLogged out successfully!\n");
}
