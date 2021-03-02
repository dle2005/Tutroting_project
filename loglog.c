#include "head.h"

void checkID(info user)
{
info sign_user;
FILE *fp=fopen("UserInfo.txt","r");
while(feof(fp)==0)
{
    fread(&sign_user,sizeof(sign_user),1,fp);
    if (strcmp(sign_user.id,user.id)==0) //존재하는 아이디면?
    {
       
        if (strcmp(sign_user.pw,user.pw)==0)
        {
            printf("login successful\n");
            Sleep(1000);
            system("clear");

            fclose(fp);
            return ;            
        }
    else 
    printf("nonexist id\n");

    }
}


}