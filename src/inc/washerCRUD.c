// 세탁기에 대한 CRUD
#include <stdio.h>
#include "washerCRUD.h"
#include "otherFunc.h"

typedef struct _washer
{
    char UserName[20]; // User 이름
    int UserNumber;    // User 학번
    int UserTime;      // 세탁기 사용 시간

} Washer;

char dormitoryInfo[2][20] = {"비전관", "벧엘관"};
char floorInfo[4][20] = {"1층", "2층", "3층", "4층"};
char washerInfo[2][20] = {"세탁기1", "세탁기2"};
// 세탁기 선택 함수
int ChoiceWasher()
{
    int dormitory = 0; // 기숙사
    int floor = 0;     // 층
    int washer = 0;    // 세탁기

    // 사용자로부터 기숙사, 층, 세탁기 정보 입력 받기 (예외처리까지)

    // 초기값 세팅
    dormitory = -1;
    floor = -1;
    washer = -1;

    printf("(1) 비전관 | (2) 벧엘관 | (0) 취소\n");
    printf("=> 기숙사를 선택하세요 : ");
    scanf("%d", &dormitory);
    println();
    if (dormitory == 0)
    {
        printf("종료되었습니다.\n");
        println();
        return 0;
    }
    else if (dormitory < 1 || dormitory > 2)
    {
        printf("입력하신 기숙사는 없습니다.\n");
        println();
        return 0;
    }

    printf("(1) 1층 | (2) 2층 | (3) 3층 | (4) 4층 | (0) 취소\n");
    printf("=> 층을 선택하세요 : ");
    scanf("%d", &floor);
    println();
    if (floor == 0)
    {
        printf("종료되었습니다.\n");
        println();
        return 0;
    }
    else if (floor < 1 || floor > 4)
    {
        printf("입력하신 층은 없습니다.\n");
        println();
        return 0;
    }

    printf("(1) 세탁기1 | (2) 세탁기2 | (0) 취소\n");
    printf("=> 세탁기를 선택하세요 : ");
    scanf("%d", &washer);
    println();
    if (washer == 0)
    {
        printf("종료되었습니다.\n");
        println();
        return 0;
    }
    else if (washer < 1 || washer > 2)
    {
        printf("입력하신 세탁기는 없습니다.\n");
        println();
        return 0;
    }

    printf("세탁하신 세탁기 정보\n");
    printf("기숙사 : %s\n", dormitoryInfo[dormitory - 1]);
    printf("층 : %s\n", floorInfo[floor - 1]);
    printf("세탁기 : %s\n", washerInfo[washer - 1]);
    println();

    // 기숙사, 층, 세탁기를 정상적으로 입력한 경우
    if (dormitory == 1)
    {
        if (floor == 1)
        {
            if (washer == 1)
            {
                return 1;
            }
            else if (washer == 2)
            {
                return 2;
            }
        }
        else if (floor == 2)
        {
            if (washer == 1)
            {
                return 3;
            }
            else if (washer == 2)
            {
                return 4;
            }
        }
        else if (floor == 3)
        {
            if (washer == 1)
            {
                return 5;
            }
            else if (washer == 2)
            {
                return 6;
            }
        }
        else if (floor == 4)
        {
            if (washer == 1)
            {
                return 7;
            }
            else if (washer == 2)
            {
                return 8;
            }
        }
    }
    else if (dormitory == 2)
    {
        if (floor == 1)
        {
            if (washer == 1)
            {
                return 9;
            }
            else if (washer == 2)
            {
                return 10;
            }
        }
        else if (floor == 2)
        {
            if (washer == 1)
            {
                return 11;
            }
            else if (washer == 2)
            {
                return 12;
            }
        }
        else if (floor == 3)
        {
            if (washer == 1)
            {
                return 13;
            }
            else if (washer == 2)
            {
                return 14;
            }
        }
        else if (floor == 4)
        {
            if (washer == 1)
            {
                return 15;
            }
            else if (washer == 2)
            {
                return 16;
            }
        }
    }
    return 0;
}
