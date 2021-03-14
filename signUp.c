#include "head.h"

void signUp() //회원가입 함수
{
    Info user; //입력한 아이디,비번 저장할 구조체 변수
    Info sign_user; 
    int i, j;

    system("clear");
    printf("id:");
    scanf("%s", &user.id);
    printf("pw:");
    scanf("%s", &user.pw);
    bool valid = validation(user);  //아이디 길이 유효성 검사
    if (!valid) //유효성 길이 범위 불일치시 회원가입 페이지로 돌아감
    {
        return signUp(); //회원가입 함수
    }

    FILE *fp = fopen("UserInfo.txt", "ab+"); //유저 정보 파일을 여는 함수
    while (feof(fp) == 0) //파일 끝까지 실행하는 반복문
    {
        fread(&sign_user, sizeof(sign_user), 1, fp); //유저 정보 파일을 앍음
        if (strcmp(sign_user.id, user.id) == 0) //문자열 비교하여 가입시 입력한 아이디와 같은 아이디 존재시 실행되는 반복문
        {
            printf("exist id\n"); 
            Sleep(1000);
            system("clear");

            fclose(fp);
            return signUp(); //회원가입 페이지로 돌아감
        }
    }

    fwrite(&user, sizeof(user), 1, fp);//기존 유저 파일에 없을시, 파일에 씀
    printf("Your membership has been successfully registered!\n");
    Sleep(1000);
    fclose(fp); //파일을 닫아줌
    system("clear");
    return;
}