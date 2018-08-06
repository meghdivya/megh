#include <iostream>
using namespace std;
class B {
    public:
        void printb() {cout<<"IN B";}
};
 
class A: public B
{
    public:
        void prita() {cout<<"IN A";}
};
 
int main() {
    // your code goes here
    A a;
    B* b=& a;
    b->printb();
    return 0;
}

