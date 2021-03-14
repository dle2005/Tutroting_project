#include "head.h"

void myvoca() //나만의 단어장
{
    int m, n;
    char answer[10];
    char ch;
    Word word;

    system("clear");
    printf("1.add word\n2.my own voca\n3.my own wordquiz\n4.quit");
    scanf("%d", &m);
    system("clear");

    if (m == 1) //나만의 단어장에 단어 추가하기
    {
        FILE *fp = fopen("MyVoca.txt", "a+"); //"MyVoca.txt" 파일 열기
        printf("English:");
        scanf("%s", &word.eng_name); //영어단어 입력 받아서 word구조체 저장
        printf("Korean:");
        scanf("%s", &word.kor_name); //한글단어 입력 받아서 word구조체 저장
        fwrite(&word, sizeof(word), 1, fp); //"MyVoca.txt" 파일에 단어 저장
        fclose(fp);
        myvoca();
    }
    else if (m == 2) //나만의 단어장 보기
    {   
        wordBook("MyVoca.txt");
        myvoca();
    }
    else if (m == 3) //나만의 단어장 단어 퀴즈
    {   printf("1.multiple choice\n2.short-answer question"); //1.객관식퀴즈 2.주관식퀴즈
        scanf("%d", &n);
        system("clear");
        if (n == 1) {
            multipleQuiz("MyVoca.txt"); //"MyVoca.txt" 파일로 객관식 퀴즈
        } else if (n == 2) {
            wordQuiz("MyVoca.txt"); //"MyVoca.txt" 파일로 주관식 퀴즈
        }
        system("clear");
        myvoca();
    }
    else if (m == 4) //메뉴로 돌아가기
    {
        menu();
    }
}