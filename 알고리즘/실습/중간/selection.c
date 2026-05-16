#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; ; x = y; y = t;} while(0)

void selection(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i; // 최솟값
        for(int j = i + 1; j < n; j++) // i+1부터 비교하면서 최소값을 min에 대입
            if(a[j]<a[min]) min = j;
        swap(int, a[i], a[min]); // 검색이 끝나면 최솟값과 i번째와 교환
    }
}

int main(void)
{
    int nx;
    puts("단순 선택 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);

    int* x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) 
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    selection(x, nx);

    puts("오름차순");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);
    return 0;
}