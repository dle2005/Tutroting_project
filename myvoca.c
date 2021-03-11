#include "head.h"

void myvoca()
{
    int m;
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
        FILE *fp = fopen("MyVoca.txt", "a+");
        while (feof(fp) == 0)
        {
            fread(&word, sizeof(word), 1, fp);
            printf("%s : %s\n", word.eng_name, word.kor_name);
        }
        fclose(fp);
        printf("PRESS ESC\n");

        while (1)
        {
            if ((ch = getch()) == 27)
            {
                system("clear");
                break;
            }
        }
        myvoca();
    }
    else if (m == 3) //단어퀴즈
    {   
        FILE *fp = fopen("MyVoca.txt", "a+");
        while (feof(fp) == 0)
        {
            fread(&word, sizeof(word), 1, fp);
            printf("%s\n", word.eng_name);
            scanf("%s", &answer);

            if (strcmp(answer, word.kor_name) == 0)
            {
                Beep(C, 70);
                Beep(E, 70);
                Beep(G, 70);
            }
            else
            {
                Beep(HC, 300);
            }
        }
        fclose(fp);
        system("clear");

        myvoca();
    }
    else if (m == 4)
    {
        menu();
    }
}