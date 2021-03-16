#include "head.h"

void myvoca(char *file_name) //나만의 단어장
{
    int menu, n;
    char answer[10];
    char ch;
    Word word;

    system("clear");
    printf("1.add word\n2.my own voca\n3.my own wordquiz\n4.exit\n");
    scanf("%d", &menu);
    system("clear");

    if (menu == 1) //나만의 단어장에 단어 추가하기
    {
        FILE *fp = fopen(file_name, "ab+"); //"MyVoca.txt" 파일 열기
        printf("English:");
        scanf("%s", &word.eng_name); //영어단어 입력 받아서 word구조체 저장
        printf("Korean:");
        scanf("%s", &word.kor_name); //한글단어 입력 받아서 word구조체 저장
        fwrite(&word, sizeof(word), 1, fp); //"MyVoca.txt" 파일에 단어 저장
        fclose(fp);
        myvoca(file_name);
    }
    else if (menu == 2) //나만의 단어장 보기
    {   
        wordBook(file_name);
        myvoca(file_name);
    }
    else if (menu == 3) //나만의 단어장 단어 퀴즈
    {   
        quizPage(file_name);
        system("clear");
        myvoca(file_name);
    }
}