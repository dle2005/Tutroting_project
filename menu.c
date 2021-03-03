#include "head.h"

void menu()
{
    int m;
    printf("1.wordbook 2.wordquiz");
    scanf("%d", &m);

    if (m == 1)
    {
        wordBook();
        menu();
    }
    else if (m == 2)
    {
        quiz();
    }
}