#include "head.h"

void main()
{
    while (1)
    {
        int i;
        printf("1. login\n");
         printf("2. register\n");

        scanf("%d", &i);
        if (i == 1)
        {
            checkID();
            break;
        }
        else if (i == 2)
            enter();
    }

    menu();

}
