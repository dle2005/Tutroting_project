#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a , const void *b);
void quiz();

typedef struct Word {
    char eng_name[20];
    char kor_name[20];
} Word;