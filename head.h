#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>



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

void signUp();
void login();

void wordBook();//단어장 실행
void findWord();//단어 찾기 실행
void wordQuiz();
int compare(const void *a, const void *b);
