#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

/*--- 노드 ---*/
typedef struct __node {
    Member        data;    /* 데이터 */
    struct __node *next;   /* 뒤쪽 노드를 가리키는 포인터 */
} Node;

/*--- 연결 리스트 관리 구조체 ---*/
typedef struct {
    Node *head;            /* 선두 노드를 가리키는 포인터 */
    Node *crnt;            /* 현재 선택한 노드를 가리키는 포인터 (주목 노드) */
} List;

/*--- 연결 리스트 초기화 ---*/
void Initialize(List *list);

/*--- 함수 매칭을 위한 비교 함수 선언 (번호/이름 검색용) ---*/
Node *Search(List *list, const Member *x, int compare(const Member *, const Member *));

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List *list, const Member *x);

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List *list, const Member *x);

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(List *list);

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(List *list);

/*--- 현재 선택한 노드(주목 노드)를 삭제 ---*/
void RemoveCurrent(List *list);

/*--- 모든 노드를 삭제 ---*/
void Clear(List *list);

/*--- 현재 선택한 노드의 데이터를 출력 ---*/
void PrintCurrent(const List *list);

/*--- 현재 선택한 노드의 데이터를 출력(줄바꿈 추가) ---*/
void PrintLnCurrent(const List *list);

/*--- 모든 노드의 데이터를 차례대로 출력 ---*/
void Print(const List *list);

/*--- 연결 리스트 종료 (메모리 해제) ---*/
void Terminate(List *list);

#endif