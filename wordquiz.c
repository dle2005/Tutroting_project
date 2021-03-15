#include "head.h"

void wordQuiz(char arr[])
{
    FILE *fp = fopen(arr, "rb"); //매개변수 arr 파일 열기
    FILE *wrongp = fopen("Wronganswer.txt", "w+"); //틀린 단어 저장할 "Wronganswer.txt"  파일 열기

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp) / sizeof(Word); //파일에 저장된 단어 수 읽기
    fseek(fp, 0, SEEK_SET);

    int rand_size = 10;
    if(file_size < 10) { //단어 수가 10개 미만일 때
        rand_size = file_size; 
    }

    Word word;
    Word wrongword[10] = {0,};
    char answer[10];
    int acc = 0;
    int j = 0;
    int m;
    char c, ch;
    int *random = (int *)malloc(sizeof(int) * rand_size);

    srand(time(NULL));

    for (int i = 0; i < rand_size; i++)
    {
        random[i] = rand() % file_size;
        for (int j = 0; j < i; j++)
        {
            if (random[i] == random[j])
            {
                i--;
                break;
            }
        }
    }

    system("clear");

    //영한 한영 옵션

    printf("1.eng-kor 2.kor-eng"); //1.영한퀴즈 2.한영퀴즈
    scanf("%d", &m);

    if (m == 1) //영한퀴즈
    {
        for (int i = 0; i < rand_size; i++)
        {

            printf("process : %d%%\n", 100 / rand_size * i); //진행률 출력
            fseek(fp, sizeof(word) * random[i], SEEK_SET);
            fread(&word, sizeof(word), 1, fp);
            printf("%s\n", word.eng_name); //영어단어 출력
            scanf("%s", &answer); //답 입력받기

            if (strcmp(answer, word.kor_name) == 0) //답과 한글단어 같을 때
            {
                Beep(C, 50);
                Beep(E, 50);
                Beep(G, 50); //딩동댕 소리
                acc += 100 / rand_size; //정확도 증가
            }
            else
            {
                Beep(HC, 150); //땡 소리
                fwrite(&word, sizeof(word), 1, wrongp); //틀린단어 "Wronganswer.txt"  파일에 쓰기
                strcpy(wrongword[j].eng_name, word.eng_name); //틀린단어 영어 복사
                strcpy(wrongword[j++].kor_name, word.kor_name); //틀린단어 한글 복사
            }
            system("clear");
        }
        fclose(fp);
        qsort(wrongword, 10, sizeof(word), compare1); //틀린단어 정렬
        printf("accuracy : %d%%\n", acc); //정확도 출력
        printf("wrong words : \n");

        fseek(wrongp, 0, SEEK_SET);

        for (int i = 0; i < j; i++)
        {
            printf("%s %s\n", wrongword[i].eng_name, wrongword[i].kor_name); //틀린단어 출력
        }

        printf("PRESS ESC\n");

        while (1)
        {
            if ((ch = getch()) == 27) //ESC키 누르면 나가기
            {
                system("clear");
                break;
            }
        }
    }
    else if (m == 2) //한영
    {
        for (int i = 0; i < rand_size; i++)
        {

            printf("process : %d%%\n", 100 / rand_size * i);
            fseek(fp, sizeof(word) * random[i], SEEK_SET);
            fread(&word, sizeof(word), 1, fp);
            printf("%s\n", word.kor_name); //한글단어 출력
            scanf("%s", &answer);

            if (strcmp(answer, word.eng_name) == 0) 
            {
                Beep(C, 50);
                Beep(E, 50);
                Beep(G, 50);
                acc += 100 / rand_size;
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

int compare1(const void *a, const void *b) //영어단어 정렬
{

    char *c1, *c2;
    c1 = ((Word *)a)->eng_name;
    c2 = ((Word *)b)->eng_name;

    return strcmp(c1, c2);
}

int compare2(const void *a, const void *b) //한글단어 정렬
{

    char *c1, *c2;
    c1 = ((Word *)a)->kor_name;
    c2 = ((Word *)b)->kor_name;

    return strcmp(c1, c2);
}