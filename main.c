#include "head.h"

void main()
{
    while (1)
    {
        int i;
        showMen();
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
