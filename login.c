#include "head.h"
void showMenU(void){
  
    printf("\n-----로그인-----\n");

    printf("       1.로그인\n");
    printf("       2.회원가입\n");

}

void checkID(){

}

void checkPass(){

}
void loadDAta(info*parr){
FILE * file =fopem("data.txt","wt");
int i=0;
for (i=0;i<3;i++)
  {
    printf("아이디:");
    scanf("%s",id);
    printf("\n");
    printf("비밀번호:");
    scanf("%s",pw);
    fprintf(file, "%s %s",id,pw);
      
  }
  flcose(fp);
  return 0;
}