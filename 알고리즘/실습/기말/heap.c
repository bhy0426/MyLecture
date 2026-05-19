#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

// 힙이 아닌 트리를 힙으로 만드는 과정
static void downheap(int a[], int left, int right)
{
    int temp = a[left];
    int child;
    int parent;
    for(parent = left; parent < (right + 1) / 2; parent = child)
    {
        int cl = parent * 2 + 1;
        int cr = cl + 1;
        child = (cr <= right && a[cr] > a[cl] ? cr : cl);
        if(temp >= a[child])
            break;
        a[parent] = a[child];
    }
    a[parent] = temp;
}

// 루트를 제거하고 힙정렬을 수행하는 과정
void heapsort(int a[], int n)
{
    for(int i = (n - 1) / 2; i >= 0; i--)
        downheap(a, i, n- 1);
    for(int i = n - 1; i > 0; i--)
    {
        swap(int, a[0], a[i]);
        downheap(a, 0, i - 1);
    }
}

int main(void)
{
    int nx;
    puts("힙 정렬");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    heapsort(x, nx);

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);
    return 0;
}