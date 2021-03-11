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

        printf("%s : %s\n", word.eng_name, word.kor_name, page);
    }
    printf("%d/10 page\n", page);

    while (1)
    {
        if (kbhit())
        {

            key = getch();
            if (key == 224 || key == 0)
            {
                key = getch();
                if (key == 75 && page > 1) // <- 누를 떄
                {
                    fseek(fp, -20 * sizeof(word), SEEK_CUR);
                    for (int i = 0; i < 10; i++)
                    {
                        fread(&word, sizeof(word), 1, fp);
                        printf("%s : %s\n", word.eng_name, word.kor_name);
                    }

                    page--;
                    printf("%d/10 page\n", page);
                }

                else if (key == 77 && page < 10) // -> 누를 때
                {

                    for (int i = 0; i < 10; i++)
                    {
                        fread(&word, sizeof(word), 1, fp);
                        printf("%s : %s\n", word.eng_name, word.kor_name);
                    }

                    page++;
                    printf("%d/10 page\n", page);
                }
            }

            else if (key == 27) //esc 누를 때
            {
                break;
            }
        }
        else
        { // 페이지 찾아서 이동
            if (page > 0 && page < 10)
            {
                printf("Enter the page you want to move\n");
                scanf("%d", &page);
                fseek(fp, ((page - 1) * 10) * sizeof(word), SEEK_SET);
                for (int i = 0; i < 10; i++)
                {
                    fread(&word, sizeof(word), 1, fp);
                    printf("%s : %s\n", word.eng_name, word.kor_name, page);
                }
                printf("%d/10 page\n", page);
            }
            else
            { //이동 가능한 페이지 초과시
                printf("Page Exceeded\n");
                Sleep(2000);
                break;
            }
        }
    }
    fclose(fp);
}