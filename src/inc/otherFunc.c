// 추가적인 함수를 구현하는 파일입니다.
#include <stdio.h>
#include <stdlib.h>
#include "userCRUD.h"
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
    int num, n = 1;
    int price;
    int check;
    List *tp;

    printf("본인의 학번을 입력하세요 > ");
    scanf("%d", &num);
    println();
    tp = ListFind(list, num); // 1이면 있고 0이면 없다

    if (tp == NULL) // tp가 어떠한 값을 가리키지 않는 경우
    {
        printf("%d번 학생은 사용자로 등록 되어있지 않습니다. \n", num);
        println();
    }
    else // tp가 어떠한 값을 가리키는 경우
    {

        printf("학번 : %d 이름 : %s\n", tp->user.studentNum, tp->user.name);
        println();

        while (n != 0)
        {
            printf("[1] 잔여 금액 확인\n");
            printf("[2] 금액 충전\n");
            printf("[3] 세제 구매\n");
            printf("[4] 섬유유연제 구매\n");
            printf("[0] 종료\n");

            printf("==> 메뉴를 선택하세요 : ");
            fflush(stdin);
            scanf("%d", &n);
            println();

            if (n == 1)
            {
                printf("%d번 학생의 잔여 금액은 %d원 입니다.\n", num, tp->user.money);
                println();
            }
            else if (n == 2)
            {
                printf("충전하고자 하는 금액을 입력하세요 > ");
                scanf("%d", &price);

                tp->user.money += price;
                println();
                printf("%d번 학생의 잔여 금액은 %d원 입니다.\n", num, tp->user.money);
                printf("충전이 완료되었습니다. 감사합니다.\n");
                println();
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
                            printf("구매가 완료되었습니다. 감사합니다.\n");
                            println();
                        }
                        else
                        {
                            printf("잔액 부족입니다.\n");
                            println();
                            tp->user.money += 500;
                        }
                        break;
                    }
                    else if (check == 2)
                    {
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
                            printf("구매가 완료되었습니다. 감사합니다.\n");
                            println();
                        }

                        else
                        {
                            printf("잔액 부족입니다.\n");
                            tp->user.money += 500;
                            println();
                        }
                        break;
                    }
                    else if (check == 2)
                    {
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
                printf("프로그램을 종료합니다.\n");
                println();

                break;
            }
            else
            {
                printf("잘못된 번호입니다. 다시 입력하세요\n");
                println();
            }
        }
    }
}