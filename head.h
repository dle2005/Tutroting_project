#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

#define HC 1046.502
#define E 659.2551
#define G 783.9909
#define C 523.2511

int compare1(const void *a , const void *b);
int compare2(const void *a , const void *b);
void enter();
void checkId();
void wordBook();
void menu();
void wordQuiz();
void myvoca();

typedef struct user_info
    {
         char id[1000];
         char pw[1000];
    } info;

typedef struct Word {
    char eng_name[20];
    char kor_name[20];
} Word;