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
            login();
            break;
        }
        else if (input == 2)
            signUp();
    }

    while (1)
    {
        system("clear");

        printf("1. wordBook\n");
        printf("2. wordQuiz\n");
        printf("3. modify pw\n");
        printf("4. my page\n");
        scanf("%d", &input);

        if (input == 1)
            wordBook();
        else if (input == 2)
            wordQuiz();
        else if (input == 3)
            changepw();
        else if (input == 4)
        mypage();
        system("clear");
    }
}
