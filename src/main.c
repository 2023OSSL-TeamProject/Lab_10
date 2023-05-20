// 이 파일을 프로그램이 구동되는 파일입니다.
#include <stdio.h>
#include <stdlib.h>
#include "userCRUD.h"
#include "washerCRUD.h"
#include "menu.h"
#include "otherFunc.h"

int main(void)
{
    List *head;

    head = malloc(sizeof(List));

    Washer *washerList[16];
    for (int i = 0; i < 16; i++)
    {
        washerList[i] = (Washer *)malloc(sizeof(Washer));
    }
    system("clear"); // 프로그램 시작 시 terminal 화면을 clear 해준다.
    ListInit(head);
    loadData(washerList);
    loadUserData(head);
    // printWasher();
    system("clear"); // 프로그램 시작 시 terminal 화면을 clear 해준다.

    while (1)
    {
        int menu = choice_menu(); // 사용자로부터 menu 번호를 받는다.
        system("clear");
        if (menu != 0)
        {
            println();
            printf("%d번 메뉴입니다.\n", menu);
            println();
        }
        else
        {
            println();
            printf("프로그램이 종료되었습니다.\n");
            println();
            break;
        }
        if (menu == 1)
        {
            ListPrint(head);
        }
        else if (menu == 2)
        {
            // success_fail(ListInsert(head));
            ListInsert(head);
        }
        else if (menu == 3)
        {
            // success_fail(ListUpdate(head));
            ListUpdate(head);
        }
        else if (menu == 4)
        {
            // success_fail(ListDelete(head));
            ListDelete(head);
        }
        else if (menu == 5)
        {
            if ((saveData(washerList) == 1) && (saveUserData(head) == 1))
            {
                printf("=> 저장되었습니다!\n");
                println();
            }
            else
            {
                printf("=> 저장되지 않았습니다.\n");
                println();
            }
        }
        else if (menu == 6)
        {
            int index = ChoiceWasher();
            if (index != 0)
            {
                WasherTimePrint(washerList[index - 1]);
            }
        }
        else if (menu == 7)
        {
            int result = WasherInsert(washerList, head);
        }
        else if (menu == 8)
        {
            int result = WasherDelete(washerList, head);
        }
        else if (menu == 9)
        {
            washerShop(head);
        }
        else if (menu == 10)
        {
        }
    }
    return 0;
}