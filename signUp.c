#include "head.h"

void signUp()
{
    Info user;
    Info sign_user;
    int i, j;

    system("clear");
    printf("id:");
    scanf("%s", &user.id);
    printf("pw:");
    scanf("%s", &user.pw);
    bool valid = validation(user);
    if (!valid)
    {
        return signUp();
    }

    FILE *fp = fopen("UserInfo.txt", "ab+");
    while (feof(fp) == 0)
    {
        fread(&sign_user, sizeof(sign_user), 1, fp);
        if (strcmp(sign_user.id, user.id) == 0)
        {
            printf("exist id\n");
            Sleep(1000);
            system("clear");

            fclose(fp);
            return signUp();
        }
    }

    fwrite(&user, sizeof(user), 1, fp);
    printf("Your membership has been successfully registered!\n");
    Sleep(1000);
    fclose(fp);
    system("clear");
    return;
}