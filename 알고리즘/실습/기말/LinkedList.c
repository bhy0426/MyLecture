#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

/*--- 하나의 노드를 동적으로 생성 (내부 함수) ---*/
static Node *AllocNode(void)
{
    return calloc(1, sizeof(Node));
}

/*--- 노드의 멤버 변수에 데이터를 설정 (내부 함수) ---*/
static void SetNode(Node *n, const Member *x, const Node *next)
{
    n->data = *x;    /* 회원 데이터 복사 */
    n->next = (Node *)next;    /* 다음 노드 포인터 설정 */
}

/*--- 연결 리스트 초기화 ---*/
void Initialize(List *list)
{
    list->head = NULL;    /* 선두 노드 포인터 초기화 */
    list->crnt = NULL;    /* 주목 노드 포인터 초기화 */
}

/*--- 함수 매칭을 통해 노드를 검색 ---*/
Node *Search(List *list, const Member *x, int compare(const Member *, const Member *))
{
    Node *ptr = list->head;
    while (ptr != NULL) {
        if (compare(&ptr->data, x) == 0) {    /* 키 값이 일치하면 */
            list->crnt = ptr;
            return ptr;    /* 검색 성공 */
        }
        ptr = ptr->next;    /* 다음 노드로 머리를 돌림 */
    }
    return NULL;    /* 검색 실패 */
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List *list, const Member *x)
{
    Node *ptr = list->head;
    list->head = list->crnt = AllocNode();
    SetNode(list->head, x, ptr);
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List *list, const Member *x)
{
    if (list->head == NULL) {    /* 리스트가 비어 있으면 */
        InsertFront(list, x);    /* 머리에 삽입 */
    } else {
        Node *ptr = list->head;
        while (ptr->next != NULL) {
            ptr = ptr->next;    /* 마지막 노드를 찾음 */
        }
        ptr->next = list->crnt = AllocNode();
        SetNode(ptr->next, x, NULL);
    }
}

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(List *list)
{
    if (list->head != NULL) {
        Node *ptr = list->head->next;    /* 두 번째 노드의 포인터 */
        free(list->head);               /* 머리 노드 메모리 해제 */
        list->head = list->crnt = ptr;  /* 새 머리 노드 설정 */
    }
}

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(List *list)
{
    if (list->head != NULL) {
        if (list->head->next == NULL) {    /* 노드가 하나뿐이면 */
            RemoveFront(list);             /* 머리 노드를 삭제 */
        } else {
            Node *ptr = list->head;
            Node *pre = list->head;
            while (ptr->next != NULL) {
                pre = ptr;
                ptr = ptr->next;    /* 마지막 노드와 그 앞 노드를 찾음 */
            }
            pre->next = NULL;       /* 앞 노드의 연결을 끊음 */
            free(ptr);              /* 마지막 노드 메모리 해제 */
            list->crnt = pre;
        }
    }
}

/*--- 현재 선택한 노드(주목 노드)를 삭제 ---*/
void RemoveCurrent(List *list)
{
    if (list->head != NULL) {
        if (list->crnt == list->head) {    /* 머리 노드를 선택 중이면 */
            RemoveFront(list);             /* 머리 노드 삭제 */
        } else {
            Node *ptr = list->head;
            while (ptr->next != list->crnt) {
                ptr = ptr->next;    /* 주목 노드의 바로 앞 노드를 찾음 */
            }
            ptr->next = list->crnt->next;    /* 주목 노드를 건너뛰고 연결 */
            free(list->crnt);               /* 주목 노드 메모리 해제 */
            list->crnt = ptr;
        }
    }
}

/*--- 모든 노드를 삭제 ---*/
void Clear(List *list)
{
    while (list->head != NULL) {
        RemoveFront(list);    /* 리스트가 빌 때까지 머리 노드를 계속 삭제 */
    }
    list->crnt = NULL;
}

/*--- 현재 선택한 노드의 데이터를 출력 ---*/
void PrintCurrent(const List *list)
{
    if (list->crnt == NULL) {
        printf("선택한 노드가 없습니다.");
    } else {
        PrintMember(&list->crnt->data);
    }
}

/*--- 현재 선택한 노드의 데이터를 출력(줄바꿈 추가) ---*/
void PrintLnCurrent(const List *list)
{
    PrintCurrent(list);
    putchar('\n');
}

/*--- 모든 노드의 데이터를 차례대로 출력 ---*/
void Print(const List *list)
{
    if (list->head == NULL) {
        puts("노드가 없습니다.");
    } else {
        Node *ptr = list->head;
        puts("【 모두 출력 】");
        while (ptr != NULL) {
            PrintLnMember(&ptr->data);
            ptr = ptr->next;
        }
    }
}

/*--- 연결 리스트 종료 (메모리 전체 해제) ---*/
void Terminate(List *list)
{
    Clear(list);    /* 모든 노드 메모리 해제 */
}