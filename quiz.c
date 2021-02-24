#include <head.h>

void quiz() {

    char word[10];
    char answer[10];
    char wrong[];
    int acc = 0;

    FILE *fp = fopen("Wordbook.txt", "r+");

    fscanf(fp, "%s", word);
    printf("%s", word);

    scanf("%s", &answer);

    if ( answer == 뜻) {
    acc += 5;
}
    else wrong[] = word;

    FILE *wp = fopen("wronganswer.txt", "w");
    fprintf(wp, "%s", wrong[]);
    fclose(wp);



}
