#include "head.h"

void multipleQuiz(char arr[])
{
    Word word, answer;
    Word wrongword[10] = { 0, };
    int an;
    int acc = 0;
    int j = 0;
    int m;
    int s = 10;
    char c, ch;
    int random[40];

    FILE *fp = fopen(arr, "rb");
    FILE *wrongp = fopen("Wronganswer.txt", "w+");

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp) / sizeof(word);
    fseek(fp, 0, SEEK_SET);

    if (filesize != s) {
        s = filesize;
    }
    printf("%d", s);

    srand(time(NULL));

    for (int i = 0; i < (s*10); i++)
    {
        random[i] = rand() % s;
        for (int j = 0; j < i; j++)
        {
            if (random[i] == random[j])
            {
                i--;
                break;
            }
        }
    }

    //영한 한영 옵션
    printf("1.eng-kor 2.kor-eng");
    scanf("%d", &m);
    system("clear");

    if (m == 1) //영한
    {
        for (int i = 0; i < s; i++)
        {
            printf("process : %d%%\n", i * s);
            int an = rand() % 4; // 0 1 2 3
            for (int j = 0; j < 4; j++)
            {
                fseek(fp, sizeof(word) * random[i + j], SEEK_SET);
                if(j == an) {
                    fread(&answer, sizeof(word), 1, fp);
                    printf("Quiz : %s\n", answer.eng_name);
                }
            }

            for (int j = 0; j < 4; j++)
            {
                fseek(fp, sizeof(word) * random[i + j], SEEK_SET);
                fread(&word, sizeof(word), 1, fp);
                printf("%d : %s\n", j+1,word.kor_name);
            }

            int input;
            scanf("%d", &input);

            if (input == an+1)
            {
                Beep(C, 50);
                Beep(E, 50);
                Beep(G, 50);
                acc += 10;
            }
            else
            {
                Beep(HC, 150);
                fwrite(&word, sizeof(word), 1, wrongp);
                strcpy(wrongword[j].eng_name, answer.eng_name);
                strcpy(wrongword[j++].kor_name, answer.kor_name);
            }
            system("clear");
        }
        fclose(fp);
        qsort(wrongword, s, sizeof(word), compare1);
        printf("accuracy : %d%%\n", acc);
        printf("wrong words : \n");

        fseek(wrongp, 0, SEEK_SET);

        for (int i = 0; i < j; i++)
        {
            printf("%s %s\n", wrongword[i].eng_name, wrongword[i].kor_name);
        }

        printf("PRESS ESC\n");

        while (1)
        {
            if ((ch = getch()) == 27)
            {
                system("clear");
                break;
            }
        }
    }
    else if (m == 2) //한영
    {
        for (int i = 0; i < 10; i++)
        {
            printf("process : %d%%\n", i * 10);
            int an = rand() % 4;
            for (int j = 0; j < 4; j++)
            {
                fseek(fp, sizeof(word) * random[i + j], SEEK_SET);
                if(j == an) {
                    fread(&answer, sizeof(word), 1, fp);
                    printf("Quiz : %s\n", answer.kor_name);
                }
            }

            for (int j = 0; j < 4; j++)
            {
                fseek(fp, sizeof(word) * random[i + j], SEEK_SET);
                fread(&word, sizeof(word), 1, fp);
                printf("%d : %s\n", j+1,word.eng_name);
            }

            int input;
            scanf("%d", &input);

            if (input == an+1)
            {
                Beep(C, 50);
                Beep(E, 50);
                Beep(G, 50);
                acc += 10;
            }
            else
            {
                Beep(HC, 150);
                fwrite(&word, sizeof(word), 1, wrongp);
                strcpy(wrongword[j].kor_name, answer.kor_name);
                strcpy(wrongword[j++].eng_name, answer.eng_name);
            }
            system("clear");
        }
        fclose(fp);
        qsort(wrongword, 10, sizeof(word), compare2);
        printf("accuracy : %d%%\n", acc);
        printf("wrong words : \n");

        fseek(wrongp, 0, SEEK_SET);

        for (int i = 0; i < j; i++)
        {
            printf("%s %s\n", wrongword[i].kor_name, wrongword[i].eng_name);
        }

        printf("PRESS ESC\n");

        while (1)
        {
            if ((ch = getch()) == 27)
            {
                system("clear");
                break;
            }
        }
    }
}
