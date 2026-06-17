#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

/*--- 하나의 노드를 동적으로 생성 (질문하신 함수!) ---*/
static BinNode *AllocBinNode(void)
{
    return calloc(1, sizeof(BinNode));
}

/*--- 노드의 멤버 변수에 데이터를 설정 ---*/
static void SetBinNode(BinNode *n, const Member *x, const BinNode *left, const BinNode *right)
{
    n->data = *x;
    n->left = (BinNode *)left;
    n->right = (BinNode *)right;
}

/*--- 검색 ---*/
BinNode *Search(BinNode *p, const Member *x)
{
    int cond;
    if (p == NULL)
        return NULL; // 검색 실패
        
    else if((cond = MemberNoCmp(x, &p->data)) == 0)
        return p; // 검색 성공

    else if(cond < 0)
        Search(p->left, x); // 왼쪽 서브 트리에서 검색

    else
        Search(p->right, x); // 오른쪽 서브 트리에서 검색
}

/*--- 노드 삽입 ---*/
BinNode *Add(BinNode *p, const Member *x)
{
    int cond;
    if (p == NULL) {
        p = AllocBinNode(); /* 빈 자리를 찾았으므로 새 노드 생성 */
        SetBinNode(p, x, NULL, NULL);
    } else if((cond = MemberNoCmp(x, &p->data)) == 0)
       printf("오류 %d는 이미 등록되어 있습니다.\n", x->no);
    else if(cond < 0)
        p->left = Add(p->left, x);
    else
        p->right = Add(p->right, x);
    return p;
}

/*--- 이진 검색 트리에서 가장 작은 노드를 찾는 함수 (삭제 보조용) ---*/
static BinNode *GetMinNode(BinNode *p)
{
    while (p->left != NULL)
        p = p->left; /* 왼쪽 끝까지 내려가면 가장 작은 값입니다 */
    return p;
}

/*--- 노드 삭제 ---*/
int Remove(BinNode **root, const Member *x)
{
    BinNode *p = *root;
    BinNode *parent = NULL;
    int isLeftChild = 1;

    /* 삭제할 노드와 그 부모 노드를 탐색 */
    while (1) {
        if (p == NULL) return -1; /* 삭제할 노드가 트리에 없음 */
        int cond = MemberNoCmp(x, &p->data);
        if (cond == 0) break; /* 찾음 */
        
        parent = p;
        if (cond < 0) {
            isLeftChild = 1;
            p = p->left;
        } else {
            isLeftChild = 0;
            p = p->right;
        }
    }

    /* 상황 1: 자식 노드가 없는 경우 또는 1개만 있는 경우 */
    if (p->left == NULL) {
        if (p == *root) *root = p->right;
        else if (isLeftChild) parent->left = p->right;
        else parent->right = p->right;
        free(p);
    } else if (p->right == NULL) {
        if (p == *root) *root = p->left;
        else if (isLeftChild) parent->left = p->left;
        else parent->right = p->left;
        free(p);
    }
    /* 상황 2: 자식 노드가 2개 모두 있는 경우 */
    else {
        // 오른쪽 서브트리에서 가장 작은 노드(대체 노드)를 찾습니다.
        BinNode *minNode = GetMinNode(p->right);
        p->data = minNode->data; /* 고른 노드의 데이터를 현재 삭제할 자리로 덮어씌움 */
        Remove(&p->right, &minNode->data); /* 자리를 양보해준 기존 미니 노드를 삭제 */
    }
    return 0;
}

/*--- 모든 노드의 데이터를 출력 (Inorder 중위 순회) ---*/
void PrintTree(const BinNode *p)
{
    if (p != NULL) {
        PrintTree(p->left);       /* 왼쪽 서브트리를 먼저 출력 */
        PrintLnMember(&p->data);  /* 나를 출력 (이러면 오름차순 정렬되어 출력됩니다) */
        PrintTree(p->right);      /* 오른쪽 서브트리를 출력 */
    }
}

/*--- 모든 노드를 삭제 (메모리 해제) ---*/
void FreeTree(BinNode *p)
{
    if (p != NULL) {
        FreeTree(p->left);  /* 왼쪽 자식들 메모리 해제 */
        FreeTree(p->right); /* 오른쪽 자식들 메모리 해제 */
        free(p);            /* 나 자신 해제 */
    }
}