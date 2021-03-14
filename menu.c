#include "head.h"

void menu()
{
    int m;
    int n;
    printf("1.wordbook\n2.wordquiz\n3.my own voca\n4.quit\n"); //1.단어장 2.단어퀴즈 3.나만의단어장 4.나가기
    scanf("%d", &m);
    system("clear");

    if (m == 1) //1.단어장
    {
        wordBook(); //단어장 보기
        menu();
    }
    else if (m == 2) //2.단어퀴즈
    {   printf("1.multiple choice\n2.short-answer question"); //1.객관식퀴즈 2.주관식퀴즈
        scanf("%d", &n);
        if (n == 1) {
            multipleQuiz("Wordbook.txt"); //"Wordbook.txt" 파일로 객관식퀴즈
        } else if (n == 2) {
            wordQuiz("Wordbook.txt"); //"Wordbook.txt" 파일로 주관식퀴즈
        }
        menu();
    }
    else if (m == 3) { //3.나만의단어장
        myvoca();
    }
    else if (m == 4) { //4.나가기
        return;
    }
}