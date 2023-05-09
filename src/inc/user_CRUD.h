// user_CRUD.c에서 사용하는 함수들을 모아 놓은 헤더파일입니다.

typedef struct _user {
    int studentNum; // user 학번
    int money; // user가 가지고있는 돈
    char name[20]; // user 이름
    char washer[20]; // 사용중인 세탁기 이름,,?
} User;

typedef struct _list {
    User user; // 노드 안에서 user의 데이터를 저장
    List *link; // list를 가리키는 링크
} List;

void ListInit(List *list); // list의 초기화를 담당한다
void Insert(List *list); // list에서 노드 추가
void Delete(List *list); // list에서 노드 삭제
void Print(List *list); // list print
void IsEmpty(List *list); // list가 비어있는지 확인
void Update(List *list); // user에 대한 정보 수정