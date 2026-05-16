#include <stdio.h>
#include <stdlib.h>

void shell(int a[], int n)
{
    // n은 배열 크기
    // n=8이면 h는 4, 2, 1의 값을 가짐
    for(int h = n / 2; h > 0; h /= 2)
    {
        // i는 n-h만큼 반복
        // n=8, h=4이면 i는 4, 5, 6, 7
        // n=8, h=2이면 i는 2,3,4,5,6,7
        for(int i = h; i < n; i++)
        {
            int tmp = a[i];
            int j;
            for(j = i - h; j >= 0 && a[j] > tmp; j-= h)
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