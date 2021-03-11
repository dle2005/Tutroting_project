#include "head.h"

void changepw()

{
    Info sign_id;

    char password[20];
    char newpw[20];
    //파일에 쓸 데이터 변수
    printf("enter pw:");
    scanf("%s", password);
    if (strcmp(login_user.pw, password) == 0)
    {
        printf("enter new password:");
        scanf("%s", newpw);
        //파일을 열어서 사용할 파일 포인터!
        FILE *fp = fopen("UserInfo.txt", "rb+"); //fopen 함수를 사용하여 파일을 바이너리 형식의 읽기모드로 연다!
        fseek(fp, 0, SEEK_SET);                  //파일 포인터를 파일의 처음으로 이동시킨다.
        while (feof(fp) == 0)                    //파일 끝까지 반복
        {
            fread(&sign_id, sizeof(sign_id), 1, fp); //파일에서 데이터를 읽음
            // printf("read: %s\n", sign_id.id);
            // Sleep(1000);
            if (strcmp(login_user.id, sign_id.id) == 0) //login_user.id와 sign_id.id의 문자열을 비교한다.
            {
                fseek(fp, -1 * (sizeof(Info)), SEEK_CUR); //파일 포인터를 앞으로 이동시킨다.
                strcpy(login_user.pw, newpw);             //newpw에 있는 문자열을 login_user.pw로 복사한다.
                // printf("new pw : %s\n", login_user.pw);
                // Sleep(1000);
                // fread(&sign_id, sizeof(sign_id), 1, fp);
                // printf("read: %s\n", sign_id.id);
                fwrite(&login_user, sizeof(Info), 1, fp); //데이터를 쓴다.
                fclose(fp);//파일을 닫는다
                return;
            }
        }
    }
    else
    {
        printf("password is wrong");
        return;
    }
}

void mypage() //마이 페이지 함수(로그아웃, 비밀번호 수정, 회원탈퇴)
{
    int put;

    printf("1. logout\n");
    printf("2. modify pw\n");
    printf("3. withdrawal\n");
    scanf("%d", &put);
    if (put == 1)
    {
        printf("<<<<<logout>>>>>");
        Sleep(1000);

        system("clear");
        return main();
    }

    else if (put == 2)
        changepw();

    else if (put == 3)
        withdrawal();
}

void withdrawal() //회원탈퇴하는 함수
{
    system("clear");
    Info sign_id;
    char pwout[20];
    printf("Please enter PW to withdraw:");
    scanf("%s", &pwout);
    FILE *fp = fopen("UserInfo.txt", "rb+");
    if (strcmp(login_user.pw, pwout) == 0)
    {
        while (feof(fp) == 0)
        {
            fread(&sign_id, sizeof(sign_id), 1, fp);    //파일에서 데이터를 읽음
            if (strcmp(login_user.id, sign_id.id) == 0) //login_user.id와 sign_id.id의 문자열을 비교한다.
            {
                fseek(fp, -1 * (sizeof(Info)), SEEK_CUR); //파일 포인터를 앞으로 이동시킨다.

                memset(login_user.id, 0, sizeof(login_user.id));
                memset(login_user.pw, 0, sizeof(login_user.pw));
                
                fwrite(&login_user, sizeof(Info), 1, fp);
                fclose(fp);

                printf("<<<<Successful membership withdrawal>>>>");
                Sleep(1000);
                system("clear");
                return main();
            }
        }
    }
    else
        printf("Wrong password");
}