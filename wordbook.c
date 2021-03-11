#include "head.h"

void wordBook(char *file_name)
{
    FILE *fp = fopen(file_name, "r");
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp) / sizeof(Word);
    fseek(fp, 0, SEEK_SET);

    Word word;
    int page_num = 1;
    int max_page_num = file_size / 10 + 1;

    printWordBook(fp, word, file_size); // 10문제 출력 함수
    printf("page_num : %d/%d\n", page_num, max_page_num);
    printf("enter ESC to exit\n");
    printf("insert page num to move if u want ");

    while (1)
    {
        if (kbhit())
        {
            int key = getch();
            if (key == 224 || key == 0) // <- or ->인 경우
            {
                key = getch();
                if (key == 75 && page_num > 1)
                {
                    fseek(fp, -(sizeof(word) * 20), SEEK_CUR); // 파일 포인터 이동

                    printWordBook(fp, word, file_size);
                    printf("page_num : %d/%d\n", --page_num, max_page_num);
                    printf("enter ESC to exit\n");
                    printf("insert page num to move if u want ");
                }
                else if (key == 77 && page_num < max_page_num)
                {
                    printWordBook(fp, word, file_size);
                    printf("page_num : %d/%d\n", ++page_num, max_page_num);
                    printf("enter ESC to exit\n");
                    printf("insert page num to move if u want ");
                }
            }
            else if (key == 27) // ESC 입력 받으면 종료
                break;
            else
            {
                int page_move;
                scanf("%d", &page_move);
                if (1 <= page_move <= max_page_num)
                {
                    printf("wrong input\n");
                    Sleep(1000);
                }
                else
                {
                    fseek(fp, sizeof(word) * (page_move - 1) * 10, SEEK_SET);
                    printWordBook(fp, word, file_size);
                    printf("page_num : %d/%d\n", ++page_num, max_page_num);
                    printf("enter ESC to exit\n");
                    printf("insert page num to move if u want ");
                }
            }
        }
    }
}

void printWordBook(FILE *fp, Word word, int file_size)
{
    system("clear");

    for (int i = 0; i < 10; i++)
    {
        if (feof(fp) != 0)
        { // 파일의 끝인 경우 종료
            fseek(fp, sizeof(word) * (10 - (file_size % 10)), SEEK_CUR);
            break;
        }
        else
        {
            fread(&word, sizeof(word), 1, fp);                 // 하나씩 읽어 오기
            printf("%s : %s\n", word.eng_name, word.kor_name); // 출력
        }
    }
}

void makeDummy()
{
    FILE *fp = fopen("Wordbook.txt", "ab+");

    for (int i = 1; i <= 77; i++)
    {
        Word word;

        sprintf(word.eng_name, "%d", i);
        sprintf(word.kor_name, "%d", i);

        fwrite(&word, sizeof(word), 1, fp);
    }
}