#include<stdio.h>

struct {
    const int* a;
    int __b;
}test;

int main()
{
    struct test A;
    A.a=(int*)malloc(sizeof(int));
    A.a=10;
    return 0;
}
