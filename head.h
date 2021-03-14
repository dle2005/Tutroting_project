#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct user_info //유저 정보를 저장할 구조체변수
{
    char id[20]; // 아이디
    char pw[20]; //비밀번호
} Info; 

typedef struct Word
{
    char eng_name[20];
    char kor_name[20];
} Word;

Info login_user; //로그인한 유저 정보 저장할 구조체변수 

void signUp(); //사용자 회원가입
void login(); //사용자 로그인
bool validation(Info); //아이디 길이 유효성 검사
void changepw(); //사용자 비밀번호 바꾸기
void wordBook();
void mypage(); //마이 페이지로 로그아웃, 비밀번호 수정, 회원탈퇴 선택가능
void wordQuiz();
void withdrawal(); //사용자 회원탈퇴
int compare(const void *a, const void *b);
