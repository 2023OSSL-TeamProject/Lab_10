// 세탁기에 대한 CRUD
#include <stdio.h>
#include <string.h>
#include "washerCRUD.h"
#include "otherFunc.h"

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

void WasherTimePrint(Washer *washList)
{

    printf("<<< 세탁기 예약 시간표 >>>\n");
    printf("\n");
    for (int i = 8; i <= 22; i++)
    {
        if (i == 8)
        {
            printf("0%d:00 ~ 0%d:00 : ", i, i + 1);
            if (washList->washerData[i - 8].UserTime == i)
            {
                printf("%s | %d\n", washList->washerData[i - 8].UserName, washList->washerData[i - 8].UserNumber);
            }
            else
            {
                printf("\n");
            }
        }
        else if (i == 9)
        {
            printf("0%d:00 ~ %d:00 : ", i, i + 1);
            if (washList->washerData[i - 8].UserTime == i)
            {
                printf("%s | %d\n", washList->washerData[i - 8].UserName, washList->washerData[i - 8].UserNumber);
            }
            else
            {
                printf("\n");
            }
        }
        else if (i >= 10)
        {
            printf("%d:00 ~ %d:00 : ", i, i + 1);
            if (washList->washerData[i - 8].UserTime == i)
            {
                printf("%s | %d\n", washList->washerData[i - 8].UserName, washList->washerData[i - 8].UserNumber);
            }
            else
            {
                printf("\n");
            }
        }
    }
    println();
};

int WasherInsert(Washer *washerList[], List *list)
{
    int studentNumber = 0;
    int ChoiceTime;
    int again = 0;
    int index = 0;
    printf("예약하고자 하는 사용자의 학번을 입력해주세요 : ");
    scanf("%d", &studentNumber);
    println();
    int check = IntListFind(list, studentNumber);
    if (check == 0)
    {
        printf("등록되어 있지 않은 학번입니다.\n");
        println();
        return 0;
    }
    else
    {
        println();
        index = ChoiceWasher();
        if (index == 0)
        {
            return 0;
        }

        WasherTimePrint(washerList[index - 1]);
        while (1)
        {
            while (1)
            {
                printf("=> 시간대를 입력하세요 (예시 : 18:00 ~ 19:00 -> 18) : ");
                ChoiceTime = 0;
                scanf("%d", &ChoiceTime);
                println();

                if (ChoiceTime < 8 || ChoiceTime > 22)
                {
                    printf("이용할 수 없는 시간대입니다.\n");
                    printf("\n");
                    again = 0;
                    printf("=> (종료 : 0 | 다시 선택 : 1) : ");
                    scanf("%d", &again);
                    println();
                    if (again == 0)
                    {
                        printf("세탁기 예약이 종료되었습니다.\n");
                        println();
                        break;
                    }
                    else
                        continue;
                }
                else
                {
                    break;
                }
            }
            List *tp = ListFind(list, studentNumber);
            if (washerList[index - 1]->washerData[ChoiceTime - 8].UserTime == ChoiceTime)
            {
                printf("이미 예약되어 있는 시간대입니다.\n");
                println();
                again = 0;
                printf("=> (종료 : 0 | 다시 선택 : 1) : ");
                scanf("%d", &again);
                println();
                if (again == 0)
                {
                    printf("세탁기 예약이 종료되었습니다.\n");
                    println();
                    break;
                }
                else
                    continue;
            }
            else
            {
                washerList[index - 1]->washerData[ChoiceTime - 8].UserNumber = tp->user.studentNum;
                strcpy(washerList[index - 1]->washerData[ChoiceTime - 8].UserName, tp->user.name);

                washerList[index - 1]->washerData[ChoiceTime - 8].UserTime = ChoiceTime;
                break;
            }
        }
    }

    return 0;
}
//
//
//
