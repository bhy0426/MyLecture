#ifndef ___BinTree
#define ___BinTree

#include "Member.h"

/*--- 노드 ---*/
typedef struct __bnode {
    Member         data;    /* 데이터 */
    struct __bnode *left;   /* 왼쪽 자식 노드를 가리키는 포인터 */
    struct __bnode *right;  /* 오른쪽 자식 노드를 가리키는 포인터 */
} BinNavi;

// 교재에 따라 BinNavi 대신 BinNode 구조체 이름으로 정의되어 있을 수 있습니다.
typedef BinNavi BinNode; 

/*--- 검색 ---*/
BinNode *Search(BinNode *p, const Member *x);

/*--- 노드 삽입 ---*/
BinNode *Add(BinNode *p, const Member *x);

/*--- 노드 삭제 ---*/
int Remove(BinNode **root, const Member *x);

/*--- 모든 노드의 데이터를 출력 ---*/
void PrintTree(const BinNode *p);

/*--- 모든 노드를 삭제 (메모리 해제) ---*/
void FreeTree(BinNode *p);

#endif