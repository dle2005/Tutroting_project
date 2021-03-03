#include "head.h"

void main() {
     int i;
    
    while (1)
    {
        showMen();
        scanf("%d", &i);
        if (i == 1)
           { checkID();
           break;
           }
            
        else if (i == 2)
            enter();
       

    }
    while(1)
    {

        quiz();
        wordbook();
    }
    
}
    
    



