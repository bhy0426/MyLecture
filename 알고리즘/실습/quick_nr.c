#include <stdio.h>
#include "IntStack.h"
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)
void quick(int a[], int left, int right)
{
    IntStack lstack;
    IntStack rstack;

    Initialize(&lstack, right - left + 1);
    Initialize(&rstack, right - left + 1);

    Push(&lstack, left);
    Push(&rstack, right);

    while(!IsEmpty(&lstack)) {
        int pl = (Pop(&lstack, &left), left);
        int pr = (Pop(&rstack, &right), right);
        int x = a[(left + right) / 2];

        do {
            while(a[pl] < x) pl++;
            while(a[pr] > x) pr--;
            if(pl <= pr) {
                swap(int, a[pl], a[pr]);
                pl++;
                pr--;
            }
        } while(pl <= pr);
        if(left < pr) {
            Push(&lstack, left);
            Push(&rstack, pr);
        }
        if(pl < right) {
            Push(&lstack, pl);
            Push(&rstack, right);
        }
    }
    Terminate(&lstack);
    Terminate(&rstack);
}