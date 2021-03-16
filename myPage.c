#include "head.h" //헤더파일 선언

void changepw() //사용자 비밀번호 바꾸는 함수
{
    system("clear");
    User sign_id; //기존 사용자 구조체

    char password[20]; //비밀번호 확인시,입력한 번호 임시저장할 변수
    char newpw[20];    //새로운 비밀번호를 임시로 저장할 변수
    //파일에 쓸 데이터 변수
    printf("enter pw:");
    scanf("%s", password);
    if (strcmp(login_user.pw, password) == 0)
    //로그인 되어 있는 비밀번호와 새로 입력한 비밀번호 문자열 비교, 일치하면 실행되는 조건문
    {
        printf("enter new password:");
        scanf("%s", newpw);
        //파일을 열어서 사용할 파일 포인터!
        FILE *fp = fopen("UserInfo.txt", "rb+"); //fopen 함수를 사용하여 파일을 바이너리 형식의 읽기모드로 연다!
        fseek(fp, 0, SEEK_SET);                  //파일 포인터를 파일의 처음으로 이동시
        while (feof(fp) == 0)                    //파일 끝까지 실행하는 반복문
        {
            fread(&sign_id, sizeof(User), 1, fp);    //파일에서 사용자의 이이디를 읽음
            if (strcmp(login_user.id, sign_id.id) == 0) //login_user.id와 sign_id.id의 문자열을 비교
            {
                fseek(fp, -1 * (sizeof(User)), SEEK_CUR); //밀려나 있는 파일 포인터를 앞으로 이동
                strcpy(login_user.pw, newpw);             //newpw에 있는 문자열을 login_user.pw로 복사

                fwrite(&login_user, sizeof(User), 1, fp); //해당 유저의 새로운 비밀번호를 입력
                fclose(fp);                               //파일을 닫아줌
                return;
            }
        }
    }
    else
    {
        printf("password is wrong");
        Sleep(1000);
    }
}

void logout() //마이 페이지 함수(로그아웃, 비밀번호 수정, 회원탈퇴)
{
    memset(login_user.id, 0, sizeof(login_user.id));
    memset(login_user.pw, 0, sizeof(login_user.pw));
    loginPage();
}