// 단어 검색후 출력
//#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD 100

//거꾸로는 안됨
        char Dic[MAX_WORD][2][20] =
            {
                {"1", "7"},
                {"2", "6"},
                {"3", "8"},
                {"4", "9"},
                {"5", "0"},
            }; //단어 쓰기

        int main(void)
        {
            char Input[128], Output[256] = {0};

            int FindWord = -1;
            int i = 0;

            while (1) { //무한 안됨

                printf("Find Word:");
                scanf("%s", Input);

                //_strlwr(Input);//대문자를 소문자로 변환

                for (i = 0; i < MAX_WORD; i++)
                {
                    if (!strcmp(Input, Dic[i][0]))
                    {
                     FindWord = 1;
                     strcpy(Output, Dic[i][1]);
                    }
                }      

                if (FindWord == -1)
                    strcpy(Output, Input);

                printf("%s:%s\n", Input, Output);

            
            }
        }