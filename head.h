#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

// int compare(const void *a , const void *b);
//void enter();
//void checkId();
void wordBook();
// void menu();
// void wordQuiz();

typedef struct user_info
    {
         char id[1000];
         char pw[1000];
    } info;

typedef struct Word {
    char eng_name[20];
    char kor_name[20];
} Word;