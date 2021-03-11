#include "head.h"

void menu()
{
    int m;
    printf("1.wordbook\n2.wordquiz\n3.my own voca\n4.quit\n");
    scanf("%d", &m);

    if (m == 1)
    {
        wordBook();
        menu();
    }
    else if (m == 2)
    {
        wordQuiz();
        menu();
    }
    else if (m == 3) {
        myvoca();
    }
    else if (m == 4) {
        return;
    }
}