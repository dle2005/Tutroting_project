#include "head.h"

void wordBook()
{
    Word word;
    int key;

    FILE *fp = fopen("Wordbook.txt", "r");

    printf("print word book\n");

    for (int i = 0; i < 10; i++)
    {
        fread(&word, sizeof(word), 1, fp);

        printf("%s : %s\n", word.eng_name, word.kor_name);
    }

    while (1)
    {
        if (kbhit())
        {

            key = getch();
            if (key == 224 || key == 0)
            {
                key = getch();
                if (key == 75)
                {
                    fseek(fp, -20 * sizeof(word), SEEK_CUR);
                    for (int i = 0; i < 10; i++)
                    {
                        fread(&word, sizeof(word), 1, fp);
                        printf("%s : %s\n", word.eng_name, word.kor_name);
                    }
                }

                else if (key == 77)
                {
                    //fread(&word, sizeof(word), 1, fp);
                    for (int i = 0; i < 10; i++)
                    {
                        fread(&word, sizeof(word), 1, fp);
                        printf("%s : %s\n", word.eng_name, word.kor_name);
                    }
                }
            }
        }
        fclose(fp);
    }
}
