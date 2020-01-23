#include<stdio.h>
#include<stdlib.h>

int main() {
    int* const p = (int *)malloc (sizeof(int)*10) ;
    const int* q = (int *)malloc (sizeof(int)*10) ;
    int i=0;
    while(i<10) {
        p[i] = i;
        printf("%d ",p[i]);
        i++;
    }
    free(q);
    //p=NULL;
    if(q) {
        printf("p is not freed");
    }
    return 0;
}
