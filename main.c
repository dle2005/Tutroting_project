#include <stdio.h>

/*void main() {
    printf("yuri~~\n");
}*/

struct Word{
 

char eng_name[20];

char kor_name[20];

};
 


void makeDummy()

{

    FILE *fp = fopen("Wordbook.txt", "ab+");

 

    for (int i = 0; i < 26; i++)

    {

        Word word;

 

        printf("eng: ");

        scanf("%s", &word.eng_name);

        printf("kor: ");

        scanf("%s", &word.kor_name);

 

        fwrite(&word, sizeof(word), 1, fp);

    }

}

 

 

fp = fopen("Wordbook.txt","ab"); 

 

fread("Wordbook.txt",filesize("Wordbook.txt"));

 

 

 

/*//for문 이용하여 10개씩 출력

 

for (i=0;i<=9;i++) {

 

   printf("단어출력하기");

}*/

 

//이동

char a;

 

printf("앞으로 이동 <- ,  뒤로 이동 -> 을 누르세요");

scanf(%c , &a);

 

if a == 75{

 

/*fseek(fp,-10, SEEK_CUR);  //앞쪽으로 이동

putchar(fgetc(fp));*/

 

}

 

 

if else a==77{

/*fseek(fp,10, SEEK_CUR);//뒤쪽으로 이동 

putchar(fgetc(fp));*/

 

}