#include "head.h" //헤더파일 선언

void changepw() //사용자 비밀번호 바꾸는 함수

{
    system("clear");
    Info sign_id; //기존 사용자 구조체

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
            fread(&sign_id, sizeof(sign_id), 1, fp);    //파일에서 사용자의 이이디를 읽음
            if (strcmp(login_user.id, sign_id.id) == 0) //login_user.id와 sign_id.id의 문자열을 비교
            {
                fseek(fp, -1 * (sizeof(Info)), SEEK_CUR); //밀려나 있는 파일 포인터를 앞으로 이동
                strcpy(login_user.pw, newpw);             //newpw에 있는 문자열을 login_user.pw로 복사

                fwrite(&login_user, sizeof(Info), 1, fp); //해당 유저의 새로운 비밀번호를 입력
                fclose(fp);                               //파일을 닫아줌
                return;
            }
        }
    }
    else
    {
        printf("password is wrong");
        Sleep(1000);
        return mypage();//비밀번호 틀릴시 다시 마이페이지 화면으로 돌아감
    }
}

void mypage() //마이 페이지 함수(로그아웃, 비밀번호 수정, 회원탈퇴)
{
    system("clear");
    int put; //메뉴로 가는 번호를 입력받아 저장하는 변수

    printf("1. logout\n");     //로그아웃
    printf("2. modify pw\n");  //바밀번호 수정
    printf("3. withdrawal\n"); //회원탈퇴
    scanf("%d", &put);
    if (put == 1)
    {
        printf("<<<<<logout>>>>>");
        Sleep(1000); //사용자에게 로그아웃 되었다는 것을 보여주기 위해 선언

        system("clear");
        return main();
    }

    else if (put == 2)
        changepw(); //비밀번호 수정

    else if (put == 3)
        withdrawal(); //회원탈퇴
}

void withdrawal() //회원탈퇴
{
    system("clear");
    Info sign_id;
    char pwout[20]; //유저가 입력한 비밀번호를 임시로 저장할 변수
    printf("Please enter PW to withdraw:");
    scanf("%s", &pwout);
    FILE *fp = fopen("UserInfo.txt", "rb+");
    if (strcmp(login_user.pw, pwout) == 0) //기존 회원의 비밀번호와 pwout에 입력된 비밀번호 문자열 비교 후 같을시 실행되는 조건문
    {
        while (feof(fp) == 0)
        {
            fread(&sign_id, sizeof(sign_id), 1, fp);    //파일에서 데이터를 읽음
            if (strcmp(login_user.id, sign_id.id) == 0) //login_user.id와 sign_id.id의 문자열을 비교후 같으면 실행
            {
                fseek(fp, -1 * (sizeof(Info)), SEEK_CUR); //파일 포인터를 앞으로 이동시킴

                memset(login_user.id, 0, sizeof(login_user.id)); //유저 아이디 사이즈 만큼 유저 아이디 메모리부분을 0으로 채움
                memset(login_user.pw, 0, sizeof(login_user.pw));// 유저 비밀번호 사이즈 만큼 유저 비밀번호 메로리부분을 0으로 채움

                fwrite(&login_user, sizeof(Info), 1, fp); //파일에 덮어씀 , 회원탈퇴
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
         Sleep(1000);
}