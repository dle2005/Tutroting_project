#include <head.h>

void quiz()
{

    Word word;
    char answer[20];
    int acc = 0;

    FILE *fp = fopen("Wordbook.txt", "r");
    FILE *wrongp = fopen("Wronganswer.txt", "w+");

    for (int i = 1; i < 11; i++)
    {
        fread(&word, sizeof(word), 1, fp);
        printf("%s\n", word.eng_name);

        scanf("%s", &answer);
        printf("진행률 : %d%%",i*5);

        if (strcmp(answer, word.kor_name) == 0)
        {
            acc += 5;
        }
        else
        {
            fwrite(&word, sizeof(word), 1, wrongp);
        }
    }
    fclose(fp);
    
    printf("정확도 : %d%%", acc);

    char *buffer;
    int size;

    fseek(wrongp, 0, SEEK_END);
    size = ftell(wrongp);

    buffer = malloc(size + 1);
    memset(buffer, 0, size + 1);

    fseek(fp, 0, SEEK_SET);
    printf("틀린 단어 : %s", buffer);

    fclose(wrongp);
    free(buffer); 
}
