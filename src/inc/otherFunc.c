// 추가적인 함수를 구현하는 파일입니다.
#include <stdio.h>
#include <stdlib.h>
#include "otherFunc.h"

void println()
{
    printf("\n-------------------------------\n\n");
}

void success_fail(int result)
{
    if (result == 1)
    {
        printf("작업 수행 성공\n");
        println();
    }
    else if (result == 0)
    {
        printf("작업 수행 실패\n");
        println();
    }
}

void washerShop(List *list)
{
    int num, check;

    printf("본인의 학번을 입력하세요 > ");
    scanf("%d", &num);

    check = ListFind(list, num); // 1이면 있고 0이면 없다

    if(check == 0)
    {
        printf("%d번 학생은 사용자로 등록 되어있지 않습니다. \n", num);
    }
    else
    {
        printf("원하는 기능을 입력하세요 > ");
    }

    // 기능 추가 및 업데이트
    // ListFind 함수 수정해야함
    // ListPrint 이용해서 출력하고, return value 수정
}