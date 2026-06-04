#include <stdio.h>

/*--- 브루트-포스법으로 문자열을 검색하는 함수 ---*/
int bf_match(const char txt[], const char pat[])
{
    int pt = 0;    /* txt를 따라가는 포인터 */
    int pp = 0;    /* pat를 따라가는 포인터 */

    // 둘 중 하나의 문자열이 끝날 때까지 반복
    while (txt[pt] != '\0' && pat[pp] != '\0') {
        if (txt[pt] == pat[pp]) {
            pt++;
            pp++;
        } else {
            pt = pt - pp + 1; // 텍스트 포인터를 다음 시작 위치로 한 칸 전진
            pp = 0;           // 패턴 포인터는 처음으로 되돌림
        }
    }

    // 패턴 문자열을 끝까지 다 맞췄다면 검색 성공! 시작 인덱스 반환
    if (pat[pp] == '\0')
        return pt - pp;
        
    return -1; // 검색 실패
}

int main(void)
{
    char s1[256];    /* 텍스트(원본 문자열) */
    char s2[256];    /* 패턴(찾을 문자열) */

    puts("브루트-포스법을 이용한 문자열 검색");

    printf("텍스트 : ");
    scanf("%s", s1);

    printf("패턴 : ");
    scanf("%s", s2);

    int idx = bf_match(s1, s2); // 문자열 검색 실행

    if (idx == -1)
        puts("텍스트에 패턴이 포함되어 있지 않습니다.");
    else
        printf("%d번째 문자부터 매치합니다.\n", idx + 1);

    return 0;
}