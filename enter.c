#include "head.h"


void enter()
{
    info user;
    info sign_user;
    int i,j;

    printf("id:");
    scanf("%s",&user.id);
    printf("pw:");
    scanf("%s",&user.pw);

    FILE *fp=fopen("UserInfo.txt","r+");
    while(feop(fp)==0)
    {
        fread(&sign_user,sizeof(sign_user),1,fp);
        if (strcmp(sign_user.id,user.id)==0)
        {
            printf("exist id\n");
            system("clear");
            fclose(fp);
            return enter();            
        }
        else if (strcmp(sign_user.id,user.id)!=0)
        {
            FILE *fp =fopen("UserInfo.txt","ab+");
            fwrite(&user,sizeof(user),1,fp);
            fclose(fp);
            return ;
        }
        


     }

    fwrite(&user,sizeof(user),1,fp);
    fclose(fp);



}   