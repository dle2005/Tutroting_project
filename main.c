#include <stdio.h>
#include <string.h>

#define PERSON 1000

void showMenu(void); //로그인 창 출력
void loadData(info *,int*); //파일로부터 데이터 읽음




void main() {
   info personal[PERSON]; //data저장
   int a=0;
   showMenu();
   loadData(personal, &a);



    
}