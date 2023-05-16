// 세탁기에 대한 CRUD
#ifndef WASHER_CRUD_H
#define WASHER_CRUD_H

#include "userCRUD.h"
typedef struct
{
    char UserName[20]; // User 이름
    int UserNumber;    // User 학번
    int UserTime;      // 세탁기 사용 시간

} WasherData;

typedef struct
{
    WasherData washerData[15];
} Washer;

int ChoiceWasher();
void WasherTimePrint(Washer *washList);
int WasherInsert(Washer *washerList[], List *list);

#endif