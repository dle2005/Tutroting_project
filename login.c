#include "head.h"

void login()
{
    Info sign_user;
    Info user;
    FILE *fp = fopen("UserInfo.txt", "rb");

    system("clear");
    printf("id:");
    scanf("%s", &user.id);
    printf("pw:");
    scanf("%s", &user.pw);

    while (feof(fp) == 0)
    {
        fread(&sign_user, sizeof(sign_user), 1, fp);
        if (strcmp(sign_user.id, user.id) == 0) //존재하는 아이디면?
        {
            if (strcmp(sign_user.pw, user.pw) == 0)
            {
                printf("login successful\n");
                strcpy(login_user.id, user.id);
                strcpy(login_user.pw, user.pw);

                Sleep(1000);
                system("clear");

                fclose(fp);
                return;
            }
            else
            {
                printf("wrong password\n");
                Sleep(1000);
                return login();
            }
        }
    }

    printf("nonexist id");
    Sleep(1000);
    return login();
}