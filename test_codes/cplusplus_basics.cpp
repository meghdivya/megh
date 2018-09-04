#include <iostream>
#include<stdio.h>
using namespace std;
class B {
    public:
        int a;
        B(){};//printb(); printf("%d\n", this->a);};
        void printb() {cout<<"IN B"<<endl;}
        virtual void f() { printf("in b virtual f\n");}
};
 
class A: public B
{
    public:
        A() { };//printb();};
        void printa() {cout<<"IN A"<<endl;}
        void f() {printf(" in a virtual f\n");};
};
 
int main() {
    // your code goes here
    A a;
    B* b=& a;
    b->printb();
    cout<<sizeof(A)<<" " << sizeof(B)<<endl;
    return 0;
}

