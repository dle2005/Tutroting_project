#include <stdio.h>
#include <string.h>

void showMenu(void); //로그인 창 출력
void loadData(info *,int*); //파일로부터 데이터 읽음

typedef struct user_info
{
     char id[1000];
     char pw[1000];
} info;