#include<stdio.h>

int main() {

    int a = 10;
    int *p = &a;

    printf("%d %d %d %d\n", a, &a, *p, p);

    return 0;
}
