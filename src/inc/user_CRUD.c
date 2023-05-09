// user에 대한 CRUD를 기능을 구현하는 파일입니다.
#include <stdio.h>
#include <stdlib.h>
#include "user_CRUD.h"

void ListInit(List *list) { // list의 초기화에 해당하는 부분
    List *tp = malloc(sizeof(List));
    tp->link = NULL; // tp라는 이름의 더미노드 하나 생성
    
    list->link = tp;
}

void Insert(List *list) {// list에서 노드 추가 / 학번, 이름 input 받아야 한다 / 돈이랑 사용하는 세탁기는 나중에 다른 함수로 따로 구현
    List *tp = malloc(sizeof(List));

    tp->user.money = 0;
    printf("사용자의 학번을 입력하시오 > ");
    scanf("%d", &tp->user.studentNum);
    printf("사용자의 이름을 입력하시오 > ");
    scanf("%s", tp->user.name);

    // Argument로 들어오는 list는 이 linked list의 head에 해당
    // 따라서 head가 가리키는 더미노드 뒤에 위치하게 하는 것이 합당

    tp->link = list->link->link; // 더미노드가 가리키는 노드를 의미
    list->link = tp; // 더미노드가 새로운 노드를 가리키게 한다
}
void Delete(List *list) { // list에서 노드 삭제 
    List *cur = list->link; // 더미노드를 가리킨다
    List *temp = list; // head를 가리킨다
    int num; // 학번 입력받을 숫자

    printf("삭제하고자 하는 학생의 학번을 입력하시오 > ");
    scanf("%d", &num);

    while(cur) {
        if(cur->user.studentNum == num) { // 원하는 학생을 찾은 경우
            temp->link = cur->link;
            free(cur);
            printf("%d 학번의 학생의 정보를 삭제하였습니다\n", num);
            return;
        }
        else { // 원하는 학생이 아닌 경우
            temp = cur;
            cur = cur->link; // 다음 노드로 이동
        }

        printf("%d 학번의 학생이 사용자 정보에 등록되어 있지 않습니다\n", num);
    }
}
void Print(List *list); // list print
void IsEmpty(List *list); // list가 비어있는지 확인