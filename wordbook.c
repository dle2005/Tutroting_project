#include "head.h"

void wordBook()
{
    Word word;
    int key;
    int page = 1;
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
                if (key == 75 && page>1) //<- 누를 떄 
                {
                    fseek(fp, -20 * sizeof(word), SEEK_CUR);
                    for (int i = 0; i < 10; i++)
                    {
                        fread(&word, sizeof(word), 1, fp);
                        printf("%s : %s\n", word.eng_name, word.kor_name);
                    }
                    page--;
                }

                else if (key == 77 && page<10) //-> 누를 때
                {
                    
                    for (int i = 0; i < 10; i++)
                    {
                        fread(&word, sizeof(word), 1, fp);
                        printf("%s : %s\n", word.eng_name, word.kor_name);
                    }
                    page++;
                }


                else if (key == 27) //esc 누를 때
                {
                    break;
                }

            }
        }
        
    }
    fclose(fp);
}





