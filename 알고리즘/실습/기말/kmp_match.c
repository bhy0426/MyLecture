#include <stdio.h>

/*--- KMP법으로 문자열을 검색하는 함수 ---*/
int kmp_match(const char txt[], const char pat[])
{
    int pt = 1;    /* txt를 따라가는 포인터 */
    int pp = 0;    /* pat를 따라가는 포인터 */
    int skip[1024]; /* 건너뛰기 표 (조견표) */

    /* 건너뛰기 표(skip table) 작성 */
    skip[pt] = 0;
    while (pat[pt] != '\0') {
        if (pat[pt] == pat[pp])
            skip[++pt] = ++pp;
        else if (pp == 0)
            skip[++pt] = pp;
        else
            pp = skip[pp];
    }   

    /* 문자열 검색 수행 */
    pt = pp = 0;
    while (txt[pt] != '\0' && pat[pp] != '\0') {
        if (txt[pt] == pat[pp]) {
            pt++;
            pp++;
        } else if (pp == 0) {
            pt++;
        } else {
            pp = skip[pp]; // 패턴을 skip[pp] 자리로 건너뛰게 만듦
        }
    }

    /* 검색 성공 시 시작 인덱스 반환 */
    if (pat[pp] == '\0')
        return pt - pp;

    return -1; // 검색 실패
}

int main(void)
{
    char s1[256];    /* 텍스트(원본 문자열) */
    char s2[256];    /* 패턴(찾을 문자열) */

    puts("KMP법을 이용한 문자열 검색");

    printf("텍스트 : ");
    scanf("%s", s1);

    printf("패턴 : ");
    scanf("%s", s2);

    int idx = kmp_match(s1, s2); // KMP 검색 실행

    if (idx == -1)
        puts("텍스트에 패턴이 포함되어 있지 않습니다.");
    else
        printf("%d번째 문자부터 매치합니다.\n", idx + 1);

    return 0;
}