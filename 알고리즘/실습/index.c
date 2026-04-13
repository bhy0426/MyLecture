#include <stdio.h>

// 원반 1 ~ 원반 no를 x 기둥에서 y 기둥으로 옮김
void move(int no, int x, int y)
{
    if(no > 1)
        // 재귀
        move(no - 1, x , 6 - x - y); // 그룹을 시작 기둥에서 중간 기둥으로

    // 바닥 원반을 목표 기둥으로
    printf("원반[%d]를 %d 기둥에서 %d 기둥으로 옮김\n", no, x, y);

    if(no > 1)
        // 재귀
        move(no - 1, 6 - x - y, x); // 그룹을 중간 기둥에서 목표 기둥으로
}

int main(void)
{
    int n;
    printf("하노이의 탑 \n 원반 개수: ");
    scanf("%d", &n);
    move(n, 1, 3); // 원반의 개수, 출발 기둥 번호, 도착 기둥 번호

    return 0;
}