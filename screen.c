#include "head.h"

void loginPage() {
    int input;
    while (1) {
        system("clear");

        printf("1. login\n"); //로그인
        printf("2. register\n");//회원가입
        printf("3. exit\n");

        scanf("%d", &input);

        if (input == 1) {
            login();
            break;
        }
        else if (input == 2)
            signUp();
        else if (input == 3)
            exit(1);
    }
}

void mainPage() {
    int input;

    while(1) {
        system("clear");

        printf("1. wordBook\n");
        printf("2. wordQuiz\n");
        printf("3. my voca\n");
        printf("4. my page\n");
        printf("5. exit\n");
       
        scanf("%d", &input);
        system("clear");

        if (input == 1)
            wordPage("Wordbook.txt");
        else if (input == 2)
            quizPage("Wordbook.txt");
        else if (input == 3) {
            char file_name[20];
            strcpy(file_name, login_user.id);
            strcat(file_name, ".txt");
            myvoca(file_name);
        }
        else if (input == 4)
            myPage();
        else if (input == 5)
            return;
    }
}

void wordPage(char *file_name) {
    int input;

    printf("1. Search\n");
    printf("2. Word Book\n");

    scanf("%d", &input);
    system("clear");

    if(input == 1)
        searchWord(file_name);
    else if(input == 2)
        wordBook(file_name);
    else {
        printf("wrong input\n");
        Sleep(1000);
    }
}

void quizPage(char *file_name) {
    int input;

    printf("1. Short Answer Quiz\n");
    printf("2. Multiple Choice Quiz\n");

    scanf("%d", &input);
    system("clear");

    if(input == 1)
        shortAnswerQuiz(file_name);
    else if(input == 2)
        multipleChoicQuiz(file_name);
    else {
        printf("wrong input\n");
        Sleep(1000);
    }
}

void myPage() {
    int input;

    printf("1. logout\n");
    printf("2. change password\n");

    scanf("%d", &input);
    system("clear");

    if(input == 1)
        logout();
    else if(input == 2)
        changepw();
    else {
        printf("wrong input\n");
        Sleep(1000);
    }
}