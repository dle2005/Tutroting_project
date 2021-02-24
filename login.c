#include "head.h"
void showMen(void){
  
    printf("\n-----로그인-----\n");

    printf("       1.로그인\n");
    printf("       2.회원가입\n");

}

void checkID(){

}

void checkPass(){

}
void loadDAta(info*parr){
FILE * file =fopen("data.txt","wt");
int i=0;
for (i=0;i<3;i++)
  {
    printf("아이디:");
    scanf("%s",parr->id);
    printf("\n");
    printf("비밀번호:");
    scanf("%s",parr->pw);
    
  }
  flcose(file);
  return 0;
}