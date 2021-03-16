#include "head.h"

void searchWord(char *file_name)
{
    FILE *fp = fopen("Wordbook.txt", "r");
    Word word;
    char input[20];
    int low = 0, high = 99, mid;

    printf("insert eng name: ");
    scanf("%s", input);

    while (low <= high)
    {
        mid = (low + high) / 2;
        fseek(fp, mid * sizeof(word), SEEK_SET);
        fread(&word, sizeof(word), 1, fp);
        if (strcmp(input, word.eng_name) == 0)
        {
            printf("%s : %s\n", word.eng_name, word.kor_name);
            systemEnd();
            return;
        }
        else if (strcmp(input, word.eng_name) == -1)
        {
            high = mid - 1;
        }
        else if (strcmp(input, word.eng_name) == 1)
            low = mid + 1;
    }
}