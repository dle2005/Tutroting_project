#include "head.h"

void changepw()

{
    Info sign_id;

    char password[20];
    char newpw[20];
    printf("enter pw:");
    scanf("%s", password);
    if (strcmp(login_user.pw, password) == 0)
    {
        printf("enter new password:");
        scanf("%s", newpw);

        FILE *fp = fopen("UserInfo.txt", "rb+");
        fseek(fp, 0, SEEK_SET);
        while (feof(fp) == 0)
        {
            fread(&sign_id, sizeof(sign_id), 1, fp);
            // printf("read: %s\n", sign_id.id);
            // Sleep(1000);
            if (strcmp(login_user.id, sign_id.id) == 0)
            {
                fseek(fp, -1 * (sizeof(Info)), SEEK_CUR);
                strcpy(login_user.pw, newpw);
                // printf("new pw : %s\n", login_user.pw);
                // Sleep(1000);
                // fread(&sign_id, sizeof(sign_id), 1, fp);
                // printf("read: %s\n", sign_id.id);
                fwrite(&login_user, sizeof(Info), 1, fp);
                fclose(fp);
                return;
            }
        }
    }
    else
    {
        printf("password is wrong");
        return;
    }
}

void mypage()
{
    int put;
    printf("1. logout\n");
    printf("2. modify pw\n");
    scanf("%d",&put);
    if (put==1)
    {
    printf("<<<<<logout>>>>>");
    Sleep(1000);
    
    system("clear");
    return main();
    }

    else if(put==2)
    changepw();
    
}