#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "CircDblLinkedList.h"

/*--- 하나의 노드를 동적으로 생성 (내부 보조 함수) ---*/
static DNode *AllocDNode(void)
{
    return calloc(1, sizeof(DNode));
}

/*--- 노드의 멤버 변수에 데이터를 설정 (내부 보조 함수) ---*/
static void SetDNode(DNode *n, const Member *x, const DNode *prev, const DNode *next)
{
    n->data = *x;
    n->prev = (DNode *)prev;
    n->next = (DNode *)next;
}

/*--- 리스트가 비어 있는지 확인 ---*/
int IsEmpty(const DList *list)
{
    // 더미 노드의 next가 자기 자신을 가리키고 있으면 비어 있는 것입니다.
    return list->head->next == list->head;
}

/*--- 연결 리스트 초기화 ---*/
void Initialize(DList *list)
{
    list->head = AllocDNode(); /* 더미 노드 생성 */
    if (list->head != NULL) {
        list->head->prev = list->head; /* 스스로 원을 그리도록 설정 */
        list->head->next = list->head;
        list->crnt = list->head;
    }
}

/*--- 함수 매칭을 통해 노드를 검색 ---*/
DNode *Search(DList *list, const Member *x, int compare(const Member *, const Member *))
{
    DNode *ptr = list->head->next; /* 더미 노드 다음의 '진짜 첫 노드'부터 출발 */
    while (ptr != list->head) {    /* 다시 더미 노드로 돌아올 때까지 한 바퀴 순회 */
        if (compare(&ptr->data, x) == 0) {
            list->crnt = ptr;
            return ptr; /* 검색 성공 */
        }
        ptr = ptr->next;
    }
    return NULL; /* 검색 실패 */
}

/*--- 현재 선택한 주목 노드의 데이터를 출력 ---*/
void PrintCurrent(const DList *list)
{
    if (IsEmpty(list))
        printf("선택한 노드가 없습니다.");
    else
        PrintMember(&list->crnt->data);
}

/*--- 현재 선택한 주목 노드의 데이터를 출력(줄바꿈 추가) ---*/
void PrintLnCurrent(const DList *list)
{
    PrintCurrent(list);
    putchar('\n');
}

/*--- 모든 노드의 데이터를 차례대로 출력 ---*/
void Print(const List *list)
{
    if (IsEmpty(list)) {
        puts("노드가 없습니다.");
    } else {
        DNode *ptr = list->head->next;
        puts("【 모두 출력 】");
        while (ptr != list->head) {
            PrintLnMember(&ptr->data);
            ptr = ptr->next;
        }
    }
}

/*--- 모든 노드의 데이터를 역순(뒤에서부터)으로 출력 ---*/
void PrintReverse(const DList *list)
{
    if (IsEmpty(list)) {
        puts("노드가 없습니다.");
    } else {
        DNode *ptr = list->head->prev; /* 더미 노드의 prev는 '가장 마지막 노드' */
        puts("【 역순 출력 】");
        while (ptr != list->head) {
            PrintLnMember(&ptr->data);
            ptr = ptr->prev; /* 앞으로 거슬러 올라감 */
        }
    }
}

/*--- 선택한 주목 노드의 바로 다음 칸으로 주목 위치를 이동 ---*/
int Next(DList *list)
{
    if (IsEmpty(list) || list->crnt->next == list->head)
        return 0; /* 이동 불가 (다음 칸이 더미 노드면 리스트의 끝) */
    list->crnt = list->crnt->next;
    return 1;
}

/*--- 선택한 주목 노드의 바로 앞 칸으로 주목 위치를 이동 ---*/
int Prev(DList *list)
{
    if (IsEmpty(list) || list->crnt->prev == list->head)
        return 0; /* 이동 불가 (앞 칸이 더미 노드면 리스트의 시작) */
    list->crnt = list->crnt->prev;
    return 1;
}

/*--- 지정한 노드 p 바로 뒤에 새 노드를 삽입 ---*/
void InsertAfter(DList *list, DNode *p, const Member *x)
{
    DNode *ptr = AllocDNode();
    DNode *nxt = p->next;

    p->next = p->next->prev = ptr;
    SetDNode(ptr, x, p, nxt);
    list->crnt = ptr;
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(DList *list, const Member *x)
{
    // 더미 노드(list->head) 바로 뒤에 넣으면 그것이 곧 '머리 삽입'입니다.
    InsertAfter(list, list->head, x);
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(DList *list, const Member *x)
{
    // 더미 노드의 앞(list->head->prev)은 항상 마지막 노드입니다.
    // 마지막 노드의 '뒤'에 넣으면 그것이 곧 '꼬리 삽입'이 됩니다.
    InsertAfter(list, list->head->prev, x);
}

/*--- 지정한 노드 p를 삭제 (내부 핵심 함수) ---*/
void Remove(DList *list, DNode *p)
{
    if (list->head != NULL && p != list->head) {
        p->prev->next = p->next; /* 내 앞 노드의 '다음'을 내 '다음 노드'로 연결 */
        p->next->prev = p->prev; /* 내 다음 노드의 '앞'을 내 '앞 노드'로 연결 */
        list->crnt = p->prev;    /* 삭제 후 주목 노드는 지운 녀석의 앞 노드로 지정 */
        free(p);                 /* 메모리 해제 */
        if (list->crnt == list->head)
            list->crnt = list->head->next; /* 만약 더미 노드로 가버렸다면 첫 노드로 보정 */
    }
}

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(DList *list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->next);
}

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(DList *list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->prev);
}

/*--- 현재 선택한 노드(주목 노드)를 삭제 ---*/
void RemoveCurrent(DList *list)
{
    if (list->crnt != list->head)
        Remove(list, list->crnt);
}

/*--- 모든 노드를 삭제 ---*/
void Clear(DList *list)
{
    while (!IsEmpty(list)) {
        RemoveFront(list); /* 리스트가 완전히 빌 때까지 머리를 계속 삭제 */
    }
}

/*--- 연결 리스트 종료 (메모리 전체 해제) ---*/
void Terminate(DList *list)
{
    Clear(list);
    free(list->head); /* 마지막으로 자리를 지키던 더미 노드까지 완전히 해제 */
    list->head = NULL;
    list->crnt = NULL;
}