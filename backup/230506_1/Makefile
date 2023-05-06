# 컴파일 작업을 자동화하기 위한 makefile입니다.
main : main.c ./inc/menu.o ./inc/otherFunc.o
	gcc main.c -o main ./inc/menu.o ./inc/otherFunc.o -I./inc
CRUD.o : ./inc/CRUD.h ./inc/CRUD.c
	gcc -c ./inc/CRUD.c -o ./inc/CRUD.o
ossCRUD.o : ./inc/menu.h ./inc/menu.c
	gcc -c ./inc/menu.c -o ./inc/menu.o
otherFunc.o : ./inc/otherFunc.h ./inc/otherFunc.c 
	gcc -c ./inc/otherFunc.c -o ./inc/otherFunc.o
clean :
	rm main ./inc/*.o 