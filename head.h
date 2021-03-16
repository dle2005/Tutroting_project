#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define HC 1046.502
#define E 659.2551
#define G 783.9909
#define C 523.2511

typedef struct User {
    char id[20];
    char pw[20];
} User;

typedef struct Word {
    char eng_name[20];
    char kor_name[20];
} Word;

User login_user;

void loginPage();
void mainPage();
void quizPage(char *);
void myPage();
void wordPage();

void signUp(); // 회원가입
void login(); // 로그인 
bool validation(User); // 아이디 유효성 검사

void logout();
void changepw();

void searchWord();
void wordBook();
void printWordBook(FILE *, Word, int);

void shortAnswerQuiz(char *arr);
void multipleChoicQuiz(char *arr);
int compare(const void *, const void *);
void getRandomNum(int *, int , int );
void systemEnd();
void printWrong(Word *, int , int);

void myvoca(char *);
