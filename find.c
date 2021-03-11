#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDS 100
 

int i, index word;

	char word[WORDS][2][30] = {
	{"1","1"}, 
	{"2","2"}, 
	{"3","3"}, 
	{"4","4"},  
	{"5","5"}, 
	}; //단어 쓰기

	char word[30]; 
	printf("찾을 단어를 입력하세요"); 
	scanf("%s", word); // 단어 입력

	
int main(void){
    
	index = 0;

	for(int i=0; i<WORDS; i++)

	{

		if(strcmp(word[index][0],word) == 0)

		{

			printf("%s : %s\n", word, word[index][1]); // 맞는 단어를 출력

			return 0;

			}

		index++;

		}

	printf("일치하는 단어가 없습니다.\n");

}