#include "head.h"

void wordQuiz(char arr[])
{
    Word word;
    Word wrongword[10] = {
        0,
    };
    char answer[10];
    int acc = 0;
    int j = 0;
    int m;
    char c, ch;
    int random[10];

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        random[i] = rand() % 100;
        for (int j = 0; j < i; j++)
        {
            if (random[i] == random[j])
            {
                i--;
                break;
            }
        }
    }

    FILE *fp = fopen(arr, "r");
    FILE *wrongp = fopen("Wronganswer.txt", "w+");
    system("clear");

 //영한 한영 옵션
    
    printf("1.eng-kor 2.kor-eng");
    scanf("%d", &m);

    if (m == 1) //영한
    {
        for (int i = 0; i < 10; i++) {   
        printf("process : %d%%\n",i*10);
        fseek(fp, sizeof(word) * random[i], SEEK_SET);
        fread(&word, sizeof(word), 1, fp);
        printf("%s\n", word.eng_name);
        scanf("%s", &answer);

        if (strcmp(answer, word.kor_name) == 0)
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
            strcpy(wrongword[j].eng_name, word.eng_name);
            strcpy(wrongword[j++].kor_name, word.kor_name);
        }
    }
    fclose(fp);
    qsort(wrongword, 10, sizeof(word), compare1);
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
        printf("process : %d%%\n",i*10);
        fseek(fp, sizeof(word) * random[i], SEEK_SET);
        fread(&word, sizeof(word), 1, fp);
        printf("%s\n", word.kor_name);
        scanf("%s", &answer);

        if (strcmp(answer, word.eng_name) == 0)
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
            strcpy(wrongword[j].kor_name, word.kor_name);
            strcpy(wrongword[j++].eng_name, word.eng_name);
        }
        system("clear");
    }
    fclose(fp);
    qsort(wrongword, 10, sizeof(word), compare2);
    printf("accuracy : %d%%\n", acc);
    printf("wrong words : \n");

    fseek(wrongp, 0, SEEK_SET);
    
    for (int i=0; i<j; i++) {
        printf("%s %s\n", wrongword[i].kor_name, wrongword[i].eng_name);
    }

    printf("PRESS ESC\n");

    while(1) {
        if ( (ch = getch()) == 27 ) {
                system("clear");
                break;
            }
        }
    }
    
}

int compare1(const void *a , const void *b){

    char *c1, *c2;
    c1 = ((Word *)a)->eng_name;
    c2 = ((Word *)b)->eng_name;

        return strcmp( c1 , c2 );

}

int compare2(const void *a , const void *b){

    char *c1, *c2;
    c1 = ((Word *)a)->kor_name;
    c2 = ((Word *)b)->kor_name;

        return strcmp( c1 , c2 );

}