#include "head.h"


void enter()
{
    info user;
    int i,j;

    printf("id:");
    scanf("%s",&user.id);
    printf("pw:");
    scanf("%s",&user.pw);

    FILE *fp=fopen("UserInfo.txt","a+");
    while(feop(fp)==0)
    {
        fread(&user,sizeof(user),1,fp);
    
    
       for(j=0;j<i-1;j++)
        {
            if(strcmp(user.id[i],user.id[j])==0)
            {
             printf("again\n");
            return enter();
            }
    
        }
       





     }

    fwrite(&user,sizeof(user),1,fp);
    fclose(fp);



}   