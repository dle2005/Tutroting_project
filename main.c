#include "head.h"

void main()
{   
    system("clear");

    while (1)
    {
        int i;

        printf("1. login\n");
        printf("2. register\n");
        scanf("%d", &i);

        if (i == 1) {
            checkId();
            break;
        } else if (i == 2) {
            enter();
            system("clear");
        }
    }
    menu();
}
