#if 0
#include <iostream>
using namespace std;

class A
{
    public:
        virtual void fun();
};

class B : public A
{
    public:
        void fun();
};

int main()
{
    int a = sizeof(A), b = sizeof(B);
    cout<<a<<" " <<b<<endl;
    if (a == b) cout << "a == b";
    else if (a > b) cout << "a > b";
    else cout << "a < b";
    return 0;
}
#endif

#include<iostream>
using namespace std;

class Test
{
    private:
        int x;
    public:
        Test(int x = 0) { this->x = x; }
        void change(Test *t) { t = this;}//this = t; }
        void print() { cout << "x = " << x << endl; }
};

int main()
{
    Test obj(5);
    Test *ptr = new Test (10);
    obj.change(ptr);
    obj.print();
    return 0;
}

