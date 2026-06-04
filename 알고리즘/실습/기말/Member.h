#ifndef ___Member
#define ___Member

/*--- 회원 데이터 ---*/
typedef struct {
    int  no;         /* 회원 번호 */
    char name[20];   /* 이름 */
} Member;

/*--- 회원 번호 비교 함수 ---*/
int MemberNoCmp(const Member *x, const Member *y);

/*--- 회원 이름 비교 함수 ---*/
int MemberNameCmp(const Member *x, const Member *y);

/*--- 회원 데이터 출력(개행 없음) ---*/
void PrintMember(const Member *x);

/*--- 회원 데이터 출력(개행 있음) ---*/
void PrintLnMember(const Member *x);

/*--- 회원 데이터 입력 ---*/
Member ScanMember(const char *message, int sw);

#endif