#include "head.h"

void main()
{
    int input;
    while (1)
    {
        system("clear");

        printf("1. login\n"); //로그인
        printf("2. register\n");//회원가입

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
        printf("3. my page\n");
       
      
        scanf("%d", &input);

        if (input == 1)
            wordBook("Wordbook.txt");
        else if (input == 2)
            wordQuiz();
        else if (input == 3)
             mypage();
        system("clear");
        
    }
}
