#include <stdio.h>
#include "IntStack.h"
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

/*--- 퀵 정렬을 비재귀적으로 구현한 프로그램 ---*/
void quick(int a[], int left, int right)
{
    IntStack lstack; // 나눌 첫 요소 인덱스 스택
    IntStack rstack; // 나눌 끝 요소 인덱스 스택

    Initialize(&lstack, right - left + 1);
    Initialize(&rstack, right - left + 1);

    Push(&lstack, left);
    Push(&rstack, right);

    while(!IsEmpty(&lstack)) {
        int pl = (Pop(&lstack, &left), left); // 왼쪽 커서
        int pr = (Pop(&rstack, &right), right); // 오른쪽 커서
        int x = a[(left + right) / 2]; // 피벗은 가운데 요소

        // 피벗을 기준으로 작은 값은 왼쪽으로, 큰 값은 오른쪽으로 이동
        do {
            while(a[pl] < x) pl++;
            while(a[pr] > x) pr--;
            if(pl <= pr) {
                swap(int, a[pl], a[pr]);
                pl++;
                pr--;
            }
        } while(pl <= pr);

        if(left < pr) {
            Push(&lstack, left); // 왼쪽 그룹 범위의
            Push(&rstack, pr); // 인덱스를 푸시
        }

        if(pl < right) {
            Push(&lstack, pl); // 오른쪽 그룹 범위의
            Push(&rstack, right); // 인덱스를 푸시
        }
    }

    Terminate(&lstack);
    Terminate(&rstack);
}

int main(void)
{
    int nx;
    printf("비재귀 퀵 정렬\n요소 개수 : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    quick_nr(x, 0, nx - 1);

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);
    return 0;
}