#include "head.h"

void menu()
{
    int m;
    int n;
    printf("1.wordbook\n2.wordquiz\n3.my own voca\n4.quit\n");
    scanf("%d", &m);
    system("clear");

    if (m == 1)
    {
        wordBook();
        menu();
    }
    else if (m == 2)
    {   printf("1.multiple choice\n2.short-answer question");
        scanf("%d", &n);
        if (n == 1) {
            multipleQuiz("Wordbook.txt");
        } else if (n == 2) {
            wordQuiz("Wordbook.txt");
        }
        menu();
    }
    else if (m == 3) {
        myvoca();
    }
    else if (m == 4) {
        return;
    }
}