#include "head.h"

void main()
{
    int i;
    
    while (1)
    {
        showMen();
        scanf("%d", &i);
        if (i == 1)
            checkID();
        else if (i == 2)
            enter();
    }
}
