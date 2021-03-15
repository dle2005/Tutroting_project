#include "head.h"

void multipleQuiz(char arr[])
{
    FILE *fp = fopen(arr, "rb"); //매개변수 arr 파일 열기
    FILE *wrongp = fopen("Wronganswer.txt", "w+"); //틀린 단어 저장할 "Wronganswer.txt"  파일 열기

    fseek(fp, 0, SEEK_END); //포인터 파일 끝으로
    long file_size = ftell(fp) / sizeof(Word); //파일에 저장된 단어 수 읽기
    fseek(fp, 0, SEEK_SET); //포인터 파일 맨앞으로
    char esc;

    if(file_size < 40) { //저장된 단어 수가 40개 미만일 경우 객관식퀴즈 불가능
        printf("words must be more than 40\n");
        printf("PRESS ESC\n"); 

        while (1)
        {
            if ((esc = getch()) == 27) //ESC키 누르면 나가기
            {
                system("clear");
                break;
            }
        }

        myvoca();
    } 

    Word word, answer;
    Word wrongword[10] = {0,}; //틀린단어 저장할 배열
    int acc = 0; //정확도
    int m, wrong_word_index = 0;
    int s = 10;
    char c, ch;
    int random[40];

    srand(time(NULL));

    for (int i = 0; i < 40; i++)
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

    
    printf("1.eng-kor 2.kor-eng"); //1. 영한퀴즈 2. 한영퀴즈
    scanf("%d", &m);
    system("clear");

    if (m == 1) //영한퀴즈
    {
        for (int i = 0; i < s; i++)
        {
            printf("process : %d%%\n", i * s); //진행률 출력
            int an = rand() % 4; // 정답으로 할 답 번호 0 1 2 3 랜덤으로 받기 
            for (int j = 0; j < 4; j++)
            {
                fseek(fp, sizeof(word) * random[i + j], SEEK_SET); //단어 랜덤하게 읽기
                if (j == an) //j와 정답으로 할 답 번호가 같을 때
                {
                    fread(&answer, sizeof(word), 1, fp);
                    printf("Quiz : %s\n", answer.eng_name); //영어단어 출력
                }
            }

            for (int j = 0; j < 4; j++)
            {
                fseek(fp, sizeof(word) * random[i + j], SEEK_SET); //단어 랜덤하게 읽기
                fread(&word, sizeof(word), 1, fp);
                printf("%d : %s\n", j + 1, word.kor_name); //객관식 1,2,3,4번 한글단어 출력
            }

            int input;
            scanf("%d", &input); //답 번호 입력 받기

            if (input == an + 1) //입력 받은 번호와 정답으로 할 번호+1이 같을 때
            {
                Beep(C, 50);
                Beep(E, 50);
                Beep(G, 50); //딩동댕 소리
                acc += 10; //정확도 10 증가
            }
            else
            {
                Beep(HC, 150); //땡 소리
                fwrite(&word, sizeof(word), 1, wrongp); //틀린단어 "Wronganswer.txt"  파일에 쓰기
                strcpy(wrongword[wrong_word_index].eng_name, answer.eng_name); //틀린단어 영어 복사
                strcpy(wrongword[wrong_word_index++].kor_name, answer.kor_name); //틀린단어 한글 복사
            }
            system("clear");
        }
        fclose(fp);
        qsort(wrongword, s, sizeof(word), compare1); //틀린단어 정렬
        printf("accuracy : %d%%\n", acc); //정확도 출력
        printf("wrong words : \n"); 

        fseek(wrongp, 0, SEEK_SET);

        for (int i = 0; i < wrong_word_index; i++) //틀린단어 출력
        {
            printf("%s %s\n", wrongword[i].eng_name, wrongword[i].kor_name); 
        }

        printf("PRESS ESC\n");

        while (1)
        {
            if ((ch = getch()) == 27) //ESC 누르면 나가기
            {
                system("clear");
                break;
            }
        }
    }
    else if (m == 2) //한영 퀴즈
    {
        for (int i = 0; i < 10; i++)
        {
            printf("process : %d%%\n", i * 10);
            int an = rand() % 4;
            for (int j = 0; j < 4; j++)
            {
                fseek(fp, sizeof(word) * random[i + j], SEEK_SET);
                if (j == an)
                {
                    fread(&answer, sizeof(word), 1, fp);
                    printf("Quiz : %s\n", answer.kor_name); //한글단어 출력
                }
            }

            for (int j = 0; j < 4; j++)
            {
                fseek(fp, sizeof(word) * random[i + j], SEEK_SET);
                fread(&word, sizeof(word), 1, fp);
                printf("%d : %s\n", j + 1, word.eng_name); //객관식 1,2,3,4번 영어단어 출력
            }

            int input;
            scanf("%d", &input);

            if (input == an + 1)
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
                strcpy(wrongword[wrong_word_index].kor_name, answer.kor_name); //틀린단어 한글 복사
                strcpy(wrongword[wrong_word_index++].eng_name, answer.eng_name); //틀린단어 영어 복사
            }
            system("clear");
        }
        fclose(fp);
        qsort(wrongword, 10, sizeof(word), compare2); //틀린단어 정렬
        printf("accuracy : %d%%\n", acc);
        printf("wrong words : \n");

        fseek(wrongp, 0, SEEK_SET);

        for (int i = 0; i < wrong_word_index; i++)
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