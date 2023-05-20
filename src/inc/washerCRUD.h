// 세탁기에 대한 CRUD
#ifndef WASHER_CRUD_H
#define WASHER_CRUD_H
#include "userCRUD.h"
// 세탁기 정보 구조체
typedef struct
{
    char UserName[20]; // User 이름
    int UserNumber;    // User 학번
    int UserTime;      // 세탁기 사용 시간

} WasherData;

// 세탁기 관리 구조체
typedef struct
{
    WasherData washerData[15];
} Washer;

int ChoiceWasher();                                 // 세탁기 선택 함수
void WasherTimePrint(Washer *washList);             // 세탁기 시간표 출력 함수
int WasherInsert(Washer *washerList[], List *list); // 세탁기 예약 함수
int WasherDelete(Washer *washerList[], List *list); // 세탁기 예약 삭제 함수
void searchWasher(int num);                         // 세탁기 정보 검색 함수

int saveData(Washer *washerList[]);  // 세탁기 정보 저장 함수
void loadData(Washer *washerList[]); // 세탁기 정보 로드 함수

#endif