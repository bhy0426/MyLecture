#ifndef ___IntStack
#define ___IntStack

#include <stdio.h>
#include <stdlib.h>

/* --- 스택 구조체 --- */
typedef struct {
    int max;    /* 스택 용량 */
    int ptr;    /* 스택 포인터 (다음에 들어올 데이터의 인덱스) */
    int *stk;   /* 스택의 첫 번째 요소에 대한 포인터 */
} IntStack;

/* --- 함수 구현 --- */

/* 1. 스택 초기화 */
static int Initialize(IntStack *s, int max) {
    s->ptr = 0;
    if ((s->stk = (int *)calloc(max, sizeof(int))) == NULL) {
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

/* 2. 푸시 */
static int Push(IntStack *s, int x) {
    if (s->ptr >= s->max) return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

/* 3. 팝 */
static int Pop(IntStack *s, int *x) {
    if (s->ptr <= 0) return -1;
    *x = s->stk[--s->ptr];
    return 0;
}

/* 4. 피크 */
static int Peek(const IntStack *s, int *x) {
    if (s->ptr <= 0) return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

/* 5. 스택의 모든 데이터 삭제 */
static void Clear(IntStack *s) {
    s->ptr = 0;
}

/* 6. 스택 용량 확인 */
static int Capacity(const IntStack *s) {
    return s->max;
}

/* 7. 데이터 개수 확인 */
static int Size(const IntStack *s) {
    return s->ptr;
}

/* 8. 스택이 비어 있는지 확인 */
static int IsEmpty(const IntStack *s) {
    return s->ptr <= 0;
}

/* 9. 스택이 가득 찼는지 확인 */
static int IsFull(const IntStack *s) {
    return s->ptr >= s->max;
}

/* 10. 스택 종료 (메모리 해제) */
static void Terminate(IntStack *s) {
    if (s->stk != NULL) {
        free(s->stk);
    }
    s->max = s->ptr = 0;
}

#endif
