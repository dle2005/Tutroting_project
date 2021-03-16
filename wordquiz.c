#include "head.h"

void shortAnswerQuiz(char *arr)
{
    FILE *fp = fopen(arr, "rb"); //매개변수 arr 파일 열기
    if(fp == NULL) {
        printf("File dosen't exist\n");
        systemEnd();
        return;
    }
    
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp) / sizeof(Word); //파일에 저장된 단어 수 읽기
    fseek(fp, 0, SEEK_SET);

    int rand_size = 10;
    if(file_size < 10) { //단어 수가 10개 미만일 때
        rand_size = file_size; 
    }

    Word word;
    Word wrongword[10] = {0,};
    char answer[20];
    int menu, accuracy = 0, wrong_count = 0;
    int *random = (int *)malloc(sizeof(int) * rand_size);

    srand(time(NULL));
    getRandomNum(random, rand_size, file_size);

    printf("1.eng-kor\n2.kor-eng\n"); //1.영한퀴즈 2.한영퀴즈
    scanf("%d", &menu);
    if(menu != 1 && menu != 2) {
        printf("wrong input\n");
        systemEnd();
        return;
    }
    system("clear");

    for (int i = 0; i < rand_size; i++)
    {
        printf("process : %d%%\n", 100 / rand_size * i); //진행률 출력
        fseek(fp, sizeof(word) * random[i], SEEK_SET);
        fread(&word, sizeof(word), 1, fp);

        if(menu == 1)
            printf("%s\n", word.eng_name); //영어단어 출력
        else
            printf("%s\n", word.kor_name);
        scanf("%s", &answer); //답 입력받기

        if (menu == 1 && strcmp(answer, word.kor_name) == 0) //답과 한글단어 같을 때
        {
            Beep(C, 50);
            Beep(E, 50);
            Beep(G, 50); //딩동댕 소리
            accuracy += 100 / rand_size; //정확도 증가
        }
        else if(menu == 2 && strcmp(answer, word.eng_name) == 0)  
        {
            Beep(C, 50);
            Beep(E, 50);
            Beep(G, 50); //딩동댕 소리
            accuracy += 100 / rand_size; //정확도 증가
        }
        else
        {
            Beep(HC, 150); //땡 소리
            strcpy(wrongword[wrong_count].eng_name, word.eng_name); //틀린단어 영어 복사
            strcpy(wrongword[wrong_count++].kor_name, word.kor_name); //틀린단어 한글 복사
        }
        system("clear");
    }
    fclose(fp);

    printWrong(wrongword, accuracy, wrong_count);

    systemEnd();
}

void multipleChoicQuiz(char *arr)
{
    FILE *fp = fopen(arr, "rb"); //매개변수 arr 파일 열기
    if(fp == NULL) {
        printf("File dosen't exist\n");
        systemEnd();
        return;
    }

    fseek(fp, 0, SEEK_END);                    //포인터 파일 끝으로
    long file_size = ftell(fp) / sizeof(Word); //파일에 저장된 단어 수 읽기
    fseek(fp, 0, SEEK_SET);                    //포인터 파일 맨앞으로

    if (file_size < 40)
    { //저장된 단어 수가 40개 미만일 경우 객관식퀴즈 불가능
        printf("words must be more than 40\n");
        systemEnd();
        return;
    }

    Word word, answer;
    Word wrongword[10] = {
        0,
    };           //틀린단어 저장할 배열
    int menu, accuracy, wrong_count = 0;
    int random[40];

    srand(time(NULL));
    getRandomNum(random, 40, file_size);

    printf("1.eng-kor\n2.kor-eng\n"); //1.영한퀴즈 2.한영퀴즈
    scanf("%d", &menu);
    if (menu != 1 && menu != 2)
    {
        printf("wrong input\n");
        systemEnd();
        return;
    }
    system("clear");

    for (int i = 0; i < 10; i++)
    {
        printf("process : %d%%\n", i * 10); //진행률 출력
        int an = rand() % 4;                // 정답으로 할 답 번호 0 1 2 3 랜덤으로 받기
        for (int j = 0; j < 4; j++)
        {
            fseek(fp, sizeof(word) * random[i + j], SEEK_SET); //단어 랜덤하게 읽기
            if (j == an)                                       //j와 정답으로 할 답 번호가 같을 때
            {
                fread(&answer, sizeof(word), 1, fp);
                if(menu == 1)
                    printf("Quiz : %s\n", answer.eng_name); //영어단어 출력
                else
                    printf("Quiz : %s\n", answer.kor_name);
            }
        }

        for (int j = 0; j < 4; j++)
        {
            fseek(fp, sizeof(word) * random[i + j], SEEK_SET); //단어 랜덤하게 읽기
            fread(&word, sizeof(word), 1, fp);
            if(menu == 1)
                printf("%d : %s\n", j + 1, word.kor_name); //객관식 1,2,3,4번 한글단어 출력
            else
                printf("%d : %s\n", j + 1, word.eng_name);
        }

        int input;
        scanf("%d", &input); //답 번호 입력 받기

        if (input == an + 1) //입력 받은 번호와 정답으로 할 번호+1이 같을 때
        {
            Beep(C, 50);
            Beep(E, 50);
            Beep(G, 50); //딩동댕 소리
            accuracy += 10;   //정확도 10 증가
        }
        else
        {
            Beep(HC, 150);                                                   //땡 소리
            strcpy(wrongword[wrong_count].eng_name, answer.eng_name);   //틀린단어 영어 복사
            strcpy(wrongword[wrong_count++].kor_name, answer.kor_name); //틀린단어 한글 복사
        }
        system("clear");
    }
    fclose(fp);

    printWrong(wrongword, accuracy, wrong_count);
    
    systemEnd();
}

int compare(const void *a, const void *b) //영어단어 정렬
{

    char *c1, *c2;
    c1 = ((Word *)a)->eng_name;
    c2 = ((Word *)b)->eng_name;

    return strcmp(c1, c2);
}

void getRandomNum(int *random, int rand_size, int file_size) {
    for (int i = 0; i < rand_size; i++) {
        random[i] = rand() % file_size;
        for (int j = 0; j < i; j++) {
            if (random[i] == random[j]) {
                i--;
                break;
            }
        }
    }
}

void systemEnd() {
    char ch;

    printf("PRESS ESC TO EXIT\n");

    while (1) {
        if ((ch = getch()) == 27) //ESC키 누르면 나가기
        {
            system("clear");
            break;
        }
    }
}

void printWrong(Word *wrongword, int accuracy, int wrong_count) {
    printf("accuracy : %d%%\n", accuracy); //정확도 출력
    printf("wrong words : \n");

    qsort(wrongword, 10, sizeof(Word), compare); //틀린단어 정렬

    for (int i = 0; i < wrong_count; i++) {
        printf("%s %s\n", wrongword[i].eng_name, wrongword[i].kor_name); //틀린단어 출력
    }
}