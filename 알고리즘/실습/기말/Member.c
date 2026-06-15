#include <stdio.h>
#include <string.h>
#include "Member.h"

/*--- 회원 번호 비교 함수 ---*/
int MemberNoCmp(const Member *x, const Member *y)
{
    if (x->no < y->no) return -1;
    if (x->no > y->no) return 1;
    return 0;
}

/*--- 회원 이름 비교 함수 ---*/
int MemberNameCmp(const Member *x, const Member *y)
{
    return strcmp(x->name, y->name);
}

/*--- 회원 데이터 출력(개행 없음) ---*/
void PrintMember(const Member *x)
{
    printf("%d %s", x->no, x->name);
}

/*--- 회원 데이터 출력(개행 있음) ---*/
void PrintLnMember(const Member *x)
{
    printf("%d %s\n", x->no, x->name);
}

/*--- 회원 데이터 입력 ---*/
Member ScanMember(const char *message, int sw)
{
    Member temp;
    printf("%s할 데이터를 입력하세요.\n", message);
    
    if (sw & MEMBER_NO) { // 또는 sw == 1 등으로 교재 버전에 따라 표현될 수 있습니다
        printf("번호: ");
        scanf("%d", &temp.no);
    }
    
    if (sw & MEMBER_NAME) {
        printf("이름: ");
        scanf("%s", temp.name);
    }
    
    return temp;
}