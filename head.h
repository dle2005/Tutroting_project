#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct user_info
{
    char id[20];
    char pw[20];
} Info;

typedef struct Word
{
    char eng_name[20];
    char kor_name[20];
} Word;

Info login_user;

void signUp();
void login();
bool validation(Info);
void changepw();
void wordBook();
void mypage();
void wordQuiz();
void withdrawal();
int compare(const void *a, const void *b);
