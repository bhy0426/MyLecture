#include <stdio.h>
#include <stdlib.h>

void merge(const int a[], int na, const int b[], int nb, int c[])
{
    int pa = 0;
    int pb = 0;
    int pc = 0;
    while(pa < na && pb < nb)
        c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];
    while(pa < na)
        c[pc++] = a[pa++];
    while(pb < nb)
        c[pc++] = b[pb++];
}

int main(void)
{
    return 0;
}