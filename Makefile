a.exe : 
	gcc head.h login.c main.c signUp.c wordbook.c wordquiz.c searchWord.c myPage.c validation.c 

clean :
	rm a.exe