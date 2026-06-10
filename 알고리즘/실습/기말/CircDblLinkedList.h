#ifndef ___CircDblLinkedList
#define ___CircDblLinkedList

#include "Member.h"

/*--- 노드 ---*/
typedef struct __node {
    Member        data;    /* 데이터 */
    struct __node *prev;   /* 앞쪽 노드를 가리키는 포인터 */
    struct __node *next;   /* 뒤쪽 노드를 가리키는 포인터 */
} DNode;

/*--- 원형 이중 연결 리스트 관리 구조체 ---*/
typedef struct {
    DNode *head;           /* 더미 노드를 가리키는 포인터 */
    DNode *crnt;           /* 현재 선택한 노드를 가리키는 포인터 (주목 노드) */
} DList;

/*--- 연결 리스트 초기화 ---*/
void Initialize(DList *list);

/*--- 리스트가 비어 있는지 확인 ---*/
int IsEmpty(const DList *list);

/*--- 함수 매칭을 통해 노드를 검색 ---*/
DNode *Search(DList *list, const Member *x, int compare(const Member *, const Member *));

/*--- 현재 선택한 노드(주목 노드)의 데이터를 출력 ---*/
void PrintCurrent(const DList *list);

/*--- 현재 선택한 노드(주목 노드)의 데이터를 출력(줄바꿈 추가) ---*/
void PrintLnCurrent(const DList *list);

/*--- 모든 노드의 데이터를 차례대로 출력 ---*/
void Print(const DList *list);

/*--- 모든 노드의 데이터를 역순(뒤에서부터)으로 출력 ---*/
void PrintReverse(const DList *list);

/*--- 선택한 주목 노드의 바로 다음 칸으로 주목 위치를 이동 ---*/
int Next(DList *list);

/*--- 선택한 주목 노드의 바로 앞 칸으로 주목 위치를 이동 ---*/
int Prev(DList *list);

/*--- 지정한 노드 바로 뒤에 새 노드를 삽입 ---*/
void InsertAfter(DList *list, DNode *p, const Member *x);

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(DList *list, const Member *x);

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(DList *list, const Member *x);

/*--- 지정한 노드를 삭제 ---*/
void Remove(DList *list, DNode *p);

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(DList *list);

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(DList *list);

/*--- 현재 선택한 노드(주목 노드)를 삭제 ---*/
void RemoveCurrent(DList *list);

/*--- 모든 노드를 삭제 ---*/
void Clear(DList *list);

/*--- 연결 리스트 종료 (메모리 전체 해제) ---*/
void Terminate(DList *list);

#endif