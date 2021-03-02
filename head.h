#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>


void enter();
void checkID();
void showMen(void);

typedef struct user_info
    {
         char id[1000];
         char pw[1000];
    } info;