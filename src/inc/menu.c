// CRUD를 제외한 나머지 메뉴 기능을 구현하는 파일입니다.
#include <stdio.h>

int choice_menu()
{

    int menu = 0;
    printf("<< H-Wasehr 예약 시스템 >>\n\n");
    printf("[1] 사용자 정보 조회\n");
    printf("[2] 사용자 추가\n");
    printf("[3] 사용자 수정\n");
    printf("[4] 사용자 삭제\n");
    printf("[5] 파일 저장\n");
    printf("[6] 세탁기 정보 조회\n");
    printf("[7] 세탁기 예약\n");
    printf("[8] 세탁기 예약 취소\n");
    printf("[9] shop\n");
    printf("[0] 프로그램 종료\n");

    printf("==> 메뉴를 선택하세요 : ");
    fflush(stdin);
    scanf("%d", &menu);
    return menu;
}