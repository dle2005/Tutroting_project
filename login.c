#include "head.h"

void login() //사용자 로그인
{
    Info sign_user; //구조체 변수 선언
    Info user; //입력한 아이디 비밀번호 저장할 구조체 선언
    FILE *fp = fopen("UserInfo.txt", "rb"); 

    system("clear");
    printf("id:");
    scanf("%s", &user.id);
    printf("pw:");
    scanf("%s", &user.pw);

    while (feof(fp) == 0) //파일 끝까지 실행하는 반복문
    {
        fread(&sign_user, sizeof(sign_user), 1, fp); //유저 파일을 불러와서 데이터를 읽음
        if (strcmp(sign_user.id, user.id) == 0) // 입력한 아이디와 데이터에 이미 존재하는 아이디가 있으면 실행되는 조건문
        {
            if (strcmp(sign_user.pw, user.pw) == 0) //유저 비밀번호를 문자열 비교를 통해 확인
            {
                printf("login successful\n");
                strcpy(login_user.id, user.id); //입력한 아이디를 login_user구조체에 문자열 복사하여 저장
                strcpy(login_user.pw, user.pw);//입력한 비밀번호를 login_user구조체에 문자열 복사하여 저장

                Sleep(1000);
                system("clear");

                fclose(fp); //열어준 파일을 닫아줌
                return;
            }
            else
            {
                printf("wrong password\n");
                Sleep(1000);
                return login(); //비밀번호 불일치시 다시 로그인 입력화면으로 돌아감
            }
        }
    }

    printf("nonexist id");
    Sleep(1000);
    return login(); //아이디 불일치시 다시 로그인 화면으로 돌아감
}