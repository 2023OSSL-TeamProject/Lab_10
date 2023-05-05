// CRUD를 제외한 나머지 메뉴 기능을 구현하는 파일입니다.
#include <stdio.h>

int choice_menu()
{

    int menu = 0;
    printf("<< 시스템 이름 >>\n");
    printf("[1] 조회\n");
    printf("[2] 추가\n");
    printf("[3] 수정\n");
    printf("[4] 취소\n");
    printf("[5] 조회(특정 값)\n");
    printf("[6] 기능 (1)\n");
    printf("[7] 기능 (2)\n");
    printf("[8] 기능 (3)\n");
    printf("[9] 기능 (4)\n");
    printf("[10] 기능 (5)\n");
    printf("[0] 프로그램 종료\n");

    printf("==> 메뉴를 선택하세요 : ");
    fflush(stdin);
    scanf("%d", &menu);
    return menu;
}