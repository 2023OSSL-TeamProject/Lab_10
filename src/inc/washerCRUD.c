// 세탁기에 대한 CRUD
#include <stdio.h>
#include "washerCRUD.h"

typedef struct _washer
{
    int studentNum; // user 학번
    char name[20];  // user 이름

} Washer;

int ChoiceWaseher()
{
    int dormitory = 0;
    int floor = 0;
    int washer = 0;

    printf("(1) 비전관 | (2) 벧엘관\n");
    printf("=> 기숙사를 선택하세요 : ");
    scanf("%d", &dormitory);
    printf("(1) 1층 | (2) 2층 | (3) 3층 | (4) 4층\n");
    printf("=> 층을 선택하세요 : ");
    scanf("%d", &floor);
    printf("(1) 세탁기1 | (2) 세탁기2\n");
    printf("=> 세탁기를 선택하세요 : ");
    printf("%d", &washer);

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
};
