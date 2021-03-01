#include "head.h"
void quiz()
{
    Word word;
    char answer[20];
    int acc = 0;
    char c, ch;
    int random[10];
    srand(time(NULL));
    for (int i = 0; i<10; i++) {
        random[i] = rand()%10;
    }

    FILE *fp = fopen("Wordbook.txt", "r");
    FILE *wrongp = fopen("Wronganswer.txt", "w+");
    system("clear");
    for (int i = 0; i < 10; i++)
    {   
        printf("process : %d%%\n",i*10);
        fseek(fp, sizeof(word) * random[i], SEEK_SET);
        fread(&word, sizeof(word), 1, fp);
        printf("%s\n", word.eng_name);

        if ( (c = getch()) == 27 ) {
            system("clear");
            printf("ESC\n");
            break;
        }
        scanf("%s", &answer);

        if (strcmp(answer, word.kor_name) == 0)
        {
            acc += 10;
        }
        else
        {
            fwrite(&word, sizeof(word), 1, wrongp);
        }
        system("clear");
    }
    fclose(fp);
    qsort(wrongp, 20, sizeof(word), strcmp); //퀵정렬
    printf("accuracy : %d%%\n", acc);
    printf("wrong words : \n");

    fseek(wrongp, 0, SEEK_SET);
    
    while (feof(wrongp) == 0) {
        fread(&word, sizeof(word), 1, wrongp);
        printf("%s : %s\n", &word.eng_name, &word.kor_name);
    }

    printf("PRESS ESC\n");

    while(1) {
        if ( (ch = getch()) == 27 ) {
                system("clear");
                break;
            }
    }
}