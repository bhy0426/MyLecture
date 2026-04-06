// 선형 검색
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*--- 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색 ---*/
int search_all(const int a[], int n, int key)
{
	int i = 0; // 배열의 인덱스를 의미함
	int cnt = 0; // 찾은 횟수

	while (i < n) {
		if (a[i] == key)
		{
			printf("%d(은)는 x[%d]에 있습니다.\n", key, i);
			cnt++;
		}
		i++;
	}
	if (cnt == 0) // 한 번도 찾지 못했으면 -1을 반환
		return -1;

	// 쓰레기 값이 들어가는 걸 방지하기 위해 1을 반환
	return 1;
}

int main(void) {
	int nx, ky;
	puts("선형 검색 (중복 원소 모두 찾기)");
	printf("요소 개수: ");
	scanf("%d", &nx);

	int* x = calloc(nx, sizeof(int)); // 요소의 개수가 nx인 int형 배열x를 생성

	for (int i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("검색값: ");
	scanf("%d", &ky);

	int idx = search_all(x, nx, ky); // 배열x의 값이 ky인 요소를 선형 검색

	if (idx == -1)
		puts("검색에 실패했습니다.");

	free(x); // 배열x를 해제
	return 0;
}