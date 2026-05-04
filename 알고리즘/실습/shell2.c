#include <stdio.h>
#include <stdlib.h>

void shell(int a[], int n)
{
    int h;
    // 1. h의 초기값을 구합니다 (n을 넘지 않는 최대의 h*3+1)
    for (h = 1; h < n; h = h * 3 + 1)
        ; // 여기는 세미콜론으로 비워둡니다.

    // 2. h를 3으로 나누면서 점점 줄여나가는 루프
    for ( ; h > 0; h /= 3)
    {
        for (int i = h; i < n; i++)
        {
            int tmp = a[i];
            int j;
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
                a[j + h] = a[j];
            a[j + h] = tmp;
        }
    }
}

int main(void)
{
    int nx;

    puts("셸 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for(int i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    shell(x, nx);

    puts("오름차순으로 정렬했습니다.");
    for(int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i , x[i]);
    free(x);

    return 0;
}