// 유클리드 호제법
#include <stdio.h>

int gcd(int x, int y)
{
    if(x == y)
        return x;
    else
    {
        if(x > y)
        {
            return gcd(y, x % y);
        }
        else
        {
            return gcd(x, y % x);
        }
    }
}

int main()
{
    // 직사각형 가로 세로 길이를 입력 받음
    int x, y;
    printf("가로 : ");
    scanf("%d", &x);
    printf("세로 : ");
    scanf("%d", &y);

    // func 호출하여 가로와 세로를 인수로 받고 큰 수를 작은 수로 나눠서 나머지를 반환
    // 작은 수와 나머지를 다시 인수로 받음
    // (나머지가 없으면) 최대공약수를 반환
    // 22 8
    // 8 6
    // 6 2
    // 2 2
    // if(x == y)
    // return x
    printf("%d %d", x, y);
    printf("최대 공약수 : %d", gcd(x, y));
    
    return 0;
}