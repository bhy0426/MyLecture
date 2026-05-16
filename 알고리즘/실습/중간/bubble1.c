#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)



void bubble(int a[], int n)
{
    for(int i = 0; i < n; i++) // 패스 횟수(n-1회)
{
	int k = 0; // 정렬을 마친 인덱스
	
	while(k < n - 1)
	{
		int last = n - 1; // 마지막으로 교환을 수행한 위치를 저장
		for(int j = n - 1; j > k; j--)
		{
			if(a[j-1] > a[j])
			{
				swap(int, a[j-1], a[j]);
				last = j; // 마지막으로 교환을 수행한 위치를 저장
			}
			k = last; // 현재 위치
		}
	}
}
}

int main(void)
{
    int nx;
    puts("버블정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);

    int* x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) 
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);

    puts("오름차순");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);
    return 0;
}