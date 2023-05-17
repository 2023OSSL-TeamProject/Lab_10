// user에 대한 CRUD를 기능을 구현하는 파일입니다.
#include <stdio.h>
#include <stdlib.h>
#include "userCRUD.h"
#include "otherFunc.h"

void ListInit(List *list)
{ // list의 초기화에 해당하는 부분
    List *tp = malloc(sizeof(List));
    tp->link = NULL;         // tp라는 이름의 더미노드 하나 생성
    tp->user.studentNum = 0; // 학번 0으로 초기화

    list->link = tp;
}

int ListInsert(List *list)
{ // list에서 노드 추가 / 학번, 이름 input 받아야 한다 / 돈이랑 사용하는 세탁기는 나중에 다른 함수로 따로 구현
    int check, num;

    printf("사용자의 학번을 입력하세요 > ");
    scanf("%d", &num);

    check = IntListFind(list, num);

    if (check == 1)
    {
        println();
        printf("이미 존재하는 사용자입니다. \n");
        println();
        return 0;
    }
    else
    {
        List *tp = malloc(sizeof(List));

        tp->user.money = 0;
        tp->user.detergent = 0;
        tp->user.fabricConditioner = 0;

        tp->user.studentNum = num; // 학번 입력
        printf("사용자의 이름을 입력하세요 > ");
        scanf("%s", tp->user.name);

        // Argument로 들어오는 list는 이 linked list의 head에 해당
        // 따라서 head가 가리키는 더미노드 뒤에 위치하게 하는 것이 합당

        tp->link = list->link->link; // 더미노드가 가리키는 노드를 의미
        list->link->link = tp;       // 더미노드가 새로운 노드를 가리키게 한다
        println();
        return 1;
    }
}
int ListDelete(List *list)
{                                 // list에서 노드 삭제
    List *cur = list->link->link; // 더미노드를 가리킨다
    List *temp = list->link;      // head를 가리킨다
    int num;                      // 학번 입력받을 숫자

    if (list->link->link == NULL)
    {
        printf("삭제할 데이터가 없습니다.\n");
        println();
        return 0;
    }
    else
    {
        printf("<<< User Information >>>\n");
        printf("\n");
        ListPrint(list);

        printf("삭제하고자 하는 학생의 학번을 입력하세요 > ");
        scanf("%d", &num);
        println();
        while (cur)
        {
            if (cur->user.studentNum == num)
            { // 원하는 학생을 찾은 경우
                temp->link = cur->link;
                free(cur);
                printf("%d 학번의 학생의 정보를 삭제하였습니다\n", num);
                println();
                return 1;
            }
            else
            { // 원하는 학생이 아닌 경우
                temp = cur;
                cur = cur->link; // 다음 노드로 이동
            }
        }
        printf("%d 학번의 학생이 사용자 정보에 등록되어 있지 않습니다\n", num);
        println();
        return 0;
    }
}
void ListPrint(List *list)
{ // list의 모든 user에 대한 내용 print
    List *cur = list->link->link;

    // printf("학번 : %d 이름 : %s\n", cur->user.studentNum, cur->user.name);
    // printf("학번 : %d 이름 : %s\n", cur->link->user.studentNum, cur->link->user.name);
    if (list->link->link == NULL)
    {
        printf("조회할 사용자 정보가 없습니다.\n");
        println();
    }
    else
    {

        while (cur)
        {
            printf("학번 : %d 이름 : %s \n", cur->user.studentNum, cur->user.name);

            cur = cur->link;
        }
        println();
    }
}
void ListIsEmpty(List *list)
{ // list가 비어있는지 여부 확인

    List *cur = list->link;

    while (cur->link)
    {
        cur = cur->link;
    }

    if (cur->user.studentNum == 0)
    { // 마지막 노드의 학번이 0인 경우
        printf("List가 비어있습니다.\n");
    }
}

int ListUpdate(List *list)
{ // user에 대한 정보 수정

    printf("<<< User Information >>>\n");
    printf("\n");
    ListPrint(list);

    int num;
    List *cur = list->link->link;

    if (list->link->link == NULL)
    {
        printf("수정할 데이터가 없습니다.\n");
        println();
        return 0;
    }
    else
    {
        printf("정보를 수정하고자 하는 학생의 학번을 입력하세요 > ");
        scanf("%d", &num);
        println();
        while (cur)
        {
            if (cur->user.studentNum == num)
            { // 찾고자 하는 학생과 이름이 동일할 경우
                printf("수정하고자 하는 학번을 입력하세요 > ");
                scanf("%d", &cur->user.studentNum);

                printf("수정하고자 하는 이름을 입력하세요 > ");
                scanf("%s", cur->user.name);
                println();
                return 1;
            }
            cur = cur->link;
        }
        printf("%d 학번의 학생은 존재하지 않습니다.\n", num);
        println();
        return 0;
    }
}

struct _list *ListFind(List *list, int num)
{ // 원하는 학생 찾으면 1 return

    List *cur = list->link->link;
    if (list->link->link == NULL)
    {
        return 0;
    }
    while (cur)
    {
        if (cur->user.studentNum == num)
        {
            return cur;
        }
        cur = cur->link;
    }
    return NULL;
}

int IntListFind(List *list, int num)
{
    List *cur = list->link->link;
    if (list->link->link == NULL)
    {
        return 0;
    }
    while (cur)
    {
        if (cur->user.studentNum == num)
        {
            printf("학번 : %d 이름 : %s\n", cur->user.studentNum, cur->user.name);
            return 1;
        }
        cur = cur->link;
    }
    return 0;
}

void saveUserData(List *list) // head를 넘겨줘야 한다
{
    FILE *fp;

    fp = fopen("./txt/userList.txt", "wt");

    List *cur = list;
    
    while(cur)
    {
        fprintf(fp, "%d %s %d %d %d", cur->user.studentNum, cur->user.name, cur->user.money, cur->user.detergent, cur->user.fabricConditioner);
        cur = cur->link;
    }

    fclose(fp);
    printf("=> user 정보 저장 완료!");
}

void loadUserData(List *list)
{
    FILE *fp;

    fp = fopen("./txt/userList.txt", "rt");

    while(feof(fp))
    {
        List *cur = malloc(sizeof(List));

        
        fscanf(fp, "%d %s %d %d %d", &cur->user.studentNum, cur->user.name, &cur->user.money, &cur->user.detergent, &cur->user.fabricConditioner);
        cur->link = list->link;
        list->link = cur;
    }

    fclose(fp);
    printf("=> 로딩 성공!");
}