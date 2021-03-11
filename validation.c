#include "head.h"

bool validation(Info user)
{
    if (strlen(user.id) > 0 && strlen(user.id) < 9)
    {
        return true;
    }
    else
    {
        printf("it must be between 0~9");
        Sleep(1000);

            return false;
    }
}
