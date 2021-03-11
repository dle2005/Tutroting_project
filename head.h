#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define HC 1046.502
#define E 659.2551
#define G 783.9909
#define C 523.2511

typedef struct user_info {
         char id[1000];
         char pw[1000];
    } info;

typedef struct Word
{
    char eng_name[20];
    char kor_name[20];
} Word;

void signUp();
void login();
bool validation(Info);

void mypage();
void changepw();

void searchWord();
void wordBook();
void printWordBook(FILE *, Word, int);
void makeDummy();

void wordQuiz(char arr[]);
void multipleQuiz(char arr[]);
void myvoca();
int compare1(const void *a , const void *b);
int compare2(const void *a , const void *b);

