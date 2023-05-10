# 컴파일 작업을 자동화하기 위한 makefile입니다.
main : main.c ./inc/menu.o ./inc/otherFunc.o ./inc/userCRUD.o ./inc/washerCRUD.o
	gcc main.c -o main ./inc/menu.o ./inc/otherFunc.o ./inc/userCRUD.o ./inc/washerCRUD.o -I./inc
userCRUD.o : ./inc/userCRUD.h ./inc/userCRUD.c
	gcc -c ./inc/userCRUD.c -o ./inc/userCRUD.o
washerCRUD.o : ./inc/washerCRUD.h ./inc/washerCRUD.c
	gcc -c ./inc/washerCRUD.c -o ./inc/washerCRUD.o
menu.o : ./inc/menu.h ./inc/menu.c
	gcc -c ./inc/menu.c -o ./inc/menu.o
otherFunc.o : ./inc/otherFunc.h ./inc/otherFunc.c 
	gcc -c ./inc/otherFunc.c -o ./inc/otherFunc.o
clean :
	rm main ./inc/*.o 