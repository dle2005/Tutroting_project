#include "head.h"

void main()
{
    int input;

    while (1)
    {
        system("clear");

        printf("1. login\n");
        printf("2. register\n");
        scanf("%d", &input);

        if (input == 1)
        {
            checkId();
            break;
        }
        else if (input == 2)
            enter();
    }

    while (1)
    {
        system("clear");

        printf("1. wordBook\n");
        printf("2. wordQuiz\n");
        scanf("%d", &input);

        if (input == 1)
            wordBook();
        else if (input == 2)
            wordQuiz();
    }
}
