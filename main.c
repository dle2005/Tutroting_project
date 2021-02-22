#include "head.h"

#define PERSON 1000

void main() {
   info personal[PERSON]; //data저장
   int a=0;
   showMenu();
   loadData(personal, &a);

}