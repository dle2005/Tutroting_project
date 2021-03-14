#include "head.h"

bool validation(Info user) //아이디 길이 범위 유효성 검사
{
    if (strlen(user.id) > 0 && strlen(user.id) < 9) //아이디 문자의 수를 세어서 0~9면 true값을 리턴함
    {
        return true;
    }
    else
    {
        printf("it must be between 0~9");
        Sleep(1000);

            return false; //0~9길이가 아닐시 false값을 리턴함
    }
}
