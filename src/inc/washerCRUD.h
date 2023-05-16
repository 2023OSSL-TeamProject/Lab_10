// 세탁기에 대한 CRUD
typedef struct
{
    char UserName[20]; // User 이름
    int UserNumber;    // User 학번
    int UserTime;      // 세탁기 사용 시간

} Washer;

int ChoiceWasher();
void WasherTimePrint();