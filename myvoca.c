#include "head.h"

void myvoca()
{
    int m, n;
    char answer[10];
    char ch;
    Word word;

    system("clear");
    printf("1.add word\n2.my own voca\n3.my own wordquiz\n4.quit");
    scanf("%d", &m);
    system("clear");

    if (m == 1) //단어추가
    {
        FILE *fp = fopen("MyVoca.txt", "a+");
        printf("English:");
        scanf("%s", &word.eng_name);
        printf("Korean:");
        scanf("%s", &word.kor_name);
        fwrite(&word, sizeof(word), 1, fp);
        fclose(fp);
        myvoca();
    }
    else if (m == 2) //나만의단어장
    {   
        wordBook("MyVoca.txt");
        myvoca();
    }
    else if (m == 3) //단어퀴즈
    {   printf("1.multiple choice\n2.short-answer question");
        scanf("%d", &n);
        system("clear");
        if (n == 1) {
            multipleQuiz("MyVoca.txt");
        } else if (n == 2) {
            wordQuiz("MyVoca.txt");
        }
        system("clear");
        myvoca();
    }
    else if (m == 4)
    {
        menu();
    }
}