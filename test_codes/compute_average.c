#include<stdio.h>

int avg(int a, int b) {
    return (a/2) + (b/2) + (a%2 + b%2)/2;
}
int main() {
    int a = 5;
    int b = 3;
    printf("%d",avg(a,b));
    return 0;
}
