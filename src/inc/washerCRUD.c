// 세탁기에 대한 CRUD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "washerCRUD.h"
#include "otherFunc.h"

char dormitoryInfo[2][20] = {"비전관", "벧엘관"};
char floorInfo[4][20] = {"1층", "2층", "3층", "4층"};
char washerInfo[2][20] = {"세탁기1", "세탁기2"};
// 세탁기 선택 함수
int ChoiceWasher()
{
    int dormitory = 0; //
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
            if (washList->washerData[i - 8].UserTime == i && washList->washerData[i - 8].UserNumber != 0)
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
            if (washList->washerData[i - 8].UserTime == i && washList->washerData[i - 8].UserNumber != 0)
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
            if (washList->washerData[i - 8].UserTime == i && washList->washerData[i - 8].UserNumber != 0)
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
        List *tp = ListFind(list, studentNumber);

        printf("잔여 금액 : %d\n", tp->user.money);
        printf("잔여 세제 : %d\n", tp->user.detergent);
        printf("잔여 섬유 : %d\n", tp->user.fabricConditioner);
        // printf("%d번 학생의 잔여 금액은 %d원 입니다.\n", 1, tp->user.money);
        // printf("%d번 학생의 세제 보유량은 %d개 이고, 섬유유연제 보유량은 %d개 입니다.\n", 1, tp->user.detergent, tp->user.fabricConditioner);

        if (tp->user.money < 1000)
        {
            printf("\n금액이 부족합니다.\n");
            println();
            return 0;
        }
        if (tp->user.detergent < 1)
        {
            printf("\n세제가 부족합니다.\n");
            println();
            return 0;
        }
        if (tp->user.fabricConditioner < 1)
        {
            printf("\n섬유유연제가 부족합니다.\n");
            println();
            return 0;
        }

        tp->user.money -= 1000;
        tp->user.detergent--;
        tp->user.fabricConditioner--;

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

int WasherDelete(Washer *washerList[], List *list)
{
    int studentNumber = 0;
    int myinfo[50][2];
    int choiceNumber = -1;

    printf("삭제하고자 하는 사용자의 학번을 입력해주세요 : ");
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
        int count = 0;
        List *tp = ListFind(list, studentNumber);

        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {

                if (washerList[i]->washerData[j].UserNumber == tp->user.studentNum)
                {
                    count++;
                    myinfo[count - 1][0] = i;
                    myinfo[count - 1][1] = j;
                }
            }
        }
        printf("\n");

        if (count != 0)
        {
            int count2 = 0;
            println();
            printf("No | 기숙사 | 사용 층 |  세탁기  | 시간 |   이름   | 학번 \n");
            for (int i = 0; i < 16; i++)
            {
                for (int j = 0; j < 16; j++)
                {

                    if (washerList[i]->washerData[j].UserNumber == tp->user.studentNum)
                    {
                        count2++;
                        printf("%d  |", count2);
                        searchWasher(i);
                        printf("| %d  | %s | %d\n", washerList[i]->washerData[j].UserTime, washerList[i]->washerData[j].UserName, washerList[i]->washerData[j].UserNumber);
                    }
                }
            }

            printf("=> 삭제할 예약 번호를 입력하세요 : ");
            scanf("%d", &choiceNumber);
            println();
            printf("Result : %d\n", count2);
            if (choiceNumber < count2 || choiceNumber > count2)
            {
                printf("없는 번호입니다.\n");
                println();
                return 0;
            }
            else
            {

                washerList[myinfo[choiceNumber - 1][0]]->washerData[myinfo[choiceNumber - 1][1]].UserNumber = 0;
                tp->user.detergent++;
                tp->user.fabricConditioner++;
                tp->user.money += 1000;

                printf("삭제되었습니다.\n");
                println();
                return 1;
            }
        }
        else if (count == 0)
        {
            printf("삭제할 예약 내역이 없습니다.\n");
            println();
            return 0;
        }
    }
    return 0;
};
void searchWasher(int num)
{
    switch (num + 1)
    {
    case 1:
        printf(" 비전관 |   1층   | 세탁기 1 ");
        break;
    case 2:
        printf(" 비전관 |   1층   | 세탁기 2 ");
        break;
    case 3:
        printf(" 비전관 |   2층   | 세탁기 1 ");
        break;
    case 4:
        printf(" 비전관 |   2층   | 세탁기 2 ");
        break;
    case 5:
        printf(" 비전관 |   3층   | 세탁기 1 ");
        break;
    case 6:
        printf(" 비전관 |   3층   | 세탁기 2 ");
        break;
    case 7:
        printf(" 비전관 |   4층   | 세탁기 1 ");
        break;
    case 8:
        printf(" 비전관 |   4층   | 세탁기 2 ");
        break;
    case 9:
        printf(" 벧엘관 |   1층   | 세탁기 1 ");
        break;
    case 10:
        printf(" 벧엘관 |   1층   | 세탁기 2 ");
        break;
    case 11:
        printf(" 벧엘관 |   2층   | 세탁기 1 ");
        break;
    case 12:
        printf(" 벧엘관 |   2층   | 세탁기 2 ");
        break;
    case 13:
        printf(" 벧엘관 |   3층   | 세탁기 1 ");
        break;
    case 14:
        printf(" 벧엘관 |   3층   | 세탁기 2 ");
        break;
    case 15:
        printf(" 벧엘관 |   4층   | 세탁기 1 ");
        break;
    case 16:
        printf(" 벧엘관 |   4층   | 세탁기 2 ");
        break;
    }
}
//
//
//

void saveData(Washer *washerList[])
{
    FILE *fp[16];
    fp[0] = fopen("./txt/washer1.txt", "wt");

    fp[1] = fopen("./txt/washer2.txt", "wt");

    fp[2] = fopen("./txt/washer3.txt", "wt");

    fp[3] = fopen("./txt/washer4.txt", "wt");

    fp[4] = fopen("./txt/washer5.txt", "wt");

    fp[5] = fopen("./txt/washer6.txt", "wt");

    fp[6] = fopen("./txt/washer7.txt", "wt");

    fp[7] = fopen("./txt/washer8.txt", "wt");

    fp[8] = fopen("./txt/washer9.txt", "wt");

    fp[9] = fopen("./txt/washe10.txt", "wt");

    fp[10] = fopen("./txt/washer11.txt", "wt");

    fp[11] = fopen("./txt/washer12.txt", "wt");

    fp[12] = fopen("./txt/washer13.txt", "wt");

    fp[13] = fopen("./txt/washer14.txt", "wt");

    fp[14] = fopen("./txt/washer15.txt", "wt");

    fp[15] = fopen("./txt/washer16.txt", "wt");

    for (int i = 0; i < 16; i++)
    {
        if (fp[i] == NULL)
        {

            printf("=> 파일 없음\n");
            return;
        }
    }

    for (int i = 0; i < 16; i++)
    {
        fprintf(fp[i], "학번      이름       세탁기 예약 시간\n");
        for (int j = 0; j < 16; j++)
        {

            if (washerList[i]->washerData[j].UserNumber > 0)
            {
                fprintf(fp[i], "%d %s %d\n", washerList[i]->washerData[j].UserNumber, washerList[i]->washerData[j].UserName, washerList[i]->washerData[j].UserTime);
            }
        }
    }
    for (int z = 0; z < 16; z++)
        fclose(fp[z]);

    printf("=> 저장됨!\n");
    println();
};

void loadData(Washer *washerList[])
{
    int count = 0, i = 0;
    FILE *fp[16];
    int j = 0;
    while (j < 16)
    {
        washerList[j] = (Washer *)malloc(sizeof(Washer));
        j++;
    }

    fp[0] = fopen("./txt/washer1.txt", "rt");

    fp[1] = fopen("./txt/washer2.txt", "rt");

    fp[2] = fopen("./txt/washer3.txt", "rt");

    fp[3] = fopen("./txt/washer4.txt", "rt");

    fp[4] = fopen("./txt/washer5.txt", "rt");

    fp[5] = fopen("./txt/washer6.txt", "rt");

    fp[6] = fopen("./txt/washer7.txt", "rt");

    fp[7] = fopen("./txt/washer8.txt", "rt");

    fp[8] = fopen("./txt/washer9.txt", "rt");

    fp[9] = fopen("./txt/washe10.txt", "rt");

    fp[10] = fopen("./txt/washer11.txt", "rt");

    fp[11] = fopen("./txt/washer12.txt", "rt");

    fp[12] = fopen("./txt/washer13.txt", "rt");

    fp[13] = fopen("./txt/washer14.txt", "rt");

    fp[14] = fopen("./txt/washer15.txt", "rt");

    fp[15] = fopen("./txt/washer16.txt", "rt");

    for (int i = 0; i < 16; i++)
    {
        if (fp[i] == NULL)
        {

            printf("=> 파일 없음\n");
            return;
        }
    }
    WasherData test;
    char temp[100];
    int a = 0;

    for (int i = 0; i < 16; i++)
    {
        fgets(temp, 100, fp[i]);
        while (fscanf(fp[i], "%d", &test.UserNumber) == 1)
        {
            if (feof(fp[i]))
                break;
            else
            {
                fscanf(fp[i], "%s", test.UserName);
                fscanf(fp[i], "%d", &test.UserTime);
            }

            for (int k = 0; k < 16; k++)
            {

                if (test.UserTime - 8 == k)
                {
                    washerList[i]->washerData[k].UserNumber = test.UserNumber;
                    washerList[i]->washerData[k].UserTime = test.UserTime;
                    strcpy(washerList[i]->washerData[k].UserName, test.UserName);
                    break;
                }
            }
        }
    }
    for (int z = 0; z < 16; z++)
        fclose(fp[z]);
    printf("=> 로딩 성공!\n\n");
};
