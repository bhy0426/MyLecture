#include <stdio.h>

int main(void)
{
    char st[8] = "ABCD";
    printf("문자열 st에는 \"%s\"가 들어있습니다. \n", &st[0]);

    return 0;
}