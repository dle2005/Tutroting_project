#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

void enter();
void checkID();
void showMen(void);
void wordBook();
void menu();

typedef struct user_info
    {
         char id[1000];
         char pw[1000];
    } info;

int compare(const void *a , const void *b);
void quiz();

typedef struct Word {
    char eng_name[20];
    char kor_name[20];
} Word;