// 추가적인 함수를 구현하는 파일입니다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userCRUD.h"
#include "otherFunc.h"
#include "washerCRUD.h"
#include <unistd.h>

// 함수 : 프로그램 출력 레이아웃을 위한 함수
void println()
{
    printf("\n-------------------------------------------------------\n\n");
}

// 함수 : 함수 성공 여부를 판단해주는 함수
// void success_fail(int result)
// {
//     if (result == 1)
//     {
//         printf("작업 수행 성공\n");
//         println();
//     }
//     else if (result == 0)
//     {
//         printf("작업 수행 실패\n");
//         println();
//     }
// }

// 함수 : 세탁기 이용을 위한 세탁 카드, 세제, 섬유유연제 조회 및 충전 함수.
void washerShop(List *list)
{
    // 변수 선언
    int num, n = 1;
    int price;
    int check;
    List *tp;

    // 사용자로부터 학번을 입력 받는 구문
    printf("본인의 학번을 입력하세요 > ");
    scanf("%d", &num);
    println();
    tp = ListFind(list, num); // 1이면 있고 0이면 없다

    system("clear");
    println();
    // 입력받은 학번의 유무 판단 구문
    if (tp == NULL) // tp가 어떠한 값을 가리키지 않는 경우
    {
        printf("%d번 학생은 사용자로 등록 되어있지 않습니다. \n", num);
        println();
    }
    else // tp가 어떠한 값을 가리키는 경우
    {
        // 입력한 사용자의 정보 출력
        printf("학번 : %d 이름 : %s\n", tp->user.studentNum, tp->user.name);
        println();

        while (n != 0)
        {
            printf("[1] 나의 정보 확인\n");
            printf("[2] 금액 충전\n");
            printf("[3] 세제 구매\n");
            printf("[4] 섬유유연제 구매\n");
            printf("[0] 종료\n");

            printf("==> 메뉴를 선택하세요 : ");
            fflush(stdin);
            scanf("%d", &n);
            println();
            system("clear");
            if (n == 1)
            {
                printf("%d번 학생의 잔여 금액은 %d원 입니다.\n", num, tp->user.money);
                printf("%d번 학생의 세제 보유량은 %d개 이고, 섬유유연제 보유량은 %d개 입니다.\n", num, tp->user.detergent, tp->user.fabricConditioner);
                println();
            }
            else if (n == 2)
            {
                printf("충전하고자 하는 금액을 입력하세요 (취소 : 0) => ");
                scanf("%d", &price);
                if (price == 0)
                {
                    system("clear");
                    println();
                    printf("충전을 취소합니다.\n");
                    println();
                }
                else
                {
                    tp->user.money += price;
                    println();
                    printf("%d번 학생의 잔여 금액은 %d원 입니다.\n", num, tp->user.money);
                    printf("충전이 완료되었습니다. 감사합니다.\n");
                    println();
                }
            }
            else if (n == 3)
            {
                while (1)
                {
                    printf("세제는 500원입니다. 구매하시겠습니까?(yes:1 no:2) > ");
                    scanf("%d", &check);
                    println();
                    if (check == 1)
                    {
                        tp->user.money -= 500;

                        if (tp->user.money >= 0)
                        {
                            tp->user.detergent++;
                            system("clear");
                            println();
                            printf("구매가 완료되었습니다. 감사합니다.\n");
                            println();
                        }
                        else
                        {
                            system("clear");
                            println();
                            printf("잔액 부족입니다.\n");
                            println();
                            tp->user.money += 500;
                        }
                        break;
                    }
                    else if (check == 2)
                    {
                        system("clear");
                        println();
                        printf("세제 구매를 종료합니다.\n");
                        println();
                        break;
                    }
                    else
                    {
                        printf("잘못된 번호입니다. 다시 입력하세요.\n");
                        println();
                    }
                }
            }
            else if (n == 4)
            {
                while (1)
                {
                    printf("섬유유연제는 500원입니다. 구매하시겠습니까?(yes:1 no:2) > ");
                    scanf("%d", &check);
                    println();
                    if (check == 1)
                    {
                        tp->user.money -= 500;

                        if (tp->user.money >= 0)
                        {
                            tp->user.fabricConditioner++;
                            system("clear");
                            println();
                            printf("구매가 완료되었습니다. 감사합니다.\n");
                            println();
                        }

                        else
                        {
                            system("clear");
                            println();
                            printf("잔액 부족입니다.\n");
                            tp->user.money += 500;
                            println();
                        }
                        break;
                    }
                    else if (check == 2)
                    {
                        system("clear");
                        println();
                        printf("섬유유연제 구매를 종료합니다.\n");
                        println();
                        break;
                    }
                    else
                    {
                        printf("잘못된 번호입니다. 다시 입력하세요.\n");
                        println();
                    }
                }
            }
            else if (n == 0)
            {
                println();
                printf("세탁기 SHOP을 종료합니다.\n");
                println();

                break;
            }
            else
            {
                println();
                printf("잘못된 번호입니다. 다시 입력하세요\n");
                println();
            }
        }
    }
}

// 프로그램 실행시 프로그램 로고를 출력해주는 함수
void printWasher()
{
    char str1[14][200] = {
        {"\n"},
        {"___________________________________________________________________________________________________________\n"},
        {"___________________________________________________________________________________________________________\n"},
        {"    _     _          __        __        __      __         ________      _     _     _______    _______\n"},
        {"   | |   | |         \\ \\      /  \\      / /     /  \\       / _______|    | |   | |   |  _____|  |  ___  |\n"},
        {"   | |___| |   ____   \\ \\    / /\\ \\    / /     / /\\ \\     | /_______     | |___| |   | |_____   | |__/  /\n"},
        {"   |  ___  |  |____|   \\ \\  / /  \\ \\  / /     / /__\\ \\     \\_______ \\    |  ___  |   |  _____|  |  __  /\n"},
        {"   | |   | |            \\ \\/ /    \\ \\/ /     / /    \\ \\    ________ |    | |   | |   | |_____   | |  \\ \\\n"},
        {"   |_|   |_|             \\__/      \\__/     /_/      \\_\\  |________/     |_|   |_|   |_______|  |_|   \\_\\\n"},
        {"___________________________________________________________________________________________________________\n"},
        {"___________________________________________________________________________________________________________\n"},
        {"\n"},
        {"\n"}};

    // 방법 1 : 한 줄씩 출력하는 방법
    // for (int i = 0; i < 14; i++)
    // {
    //     for (int j = 0; j < strlen(str1[i]); j++)
    //     {

    //         printf("%c", str1[i][j]);
    //     }
    //     usleep(200000);
    // }
    // sleep(2);

    // 방법 2 : 글자 하나씩 출력하는 방법
    for (int i = 0; i < 14; i++)
    {
        int length = strlen(str1[i]);
        for (int j = 0; j < length; j++)
        {

            printf("%c", str1[i][j]);
            fflush(stdout);
            usleep(2000);
        }
    }
    printf("환영합니다. H-Washer입니다!\n\n");
    sleep(3);
}