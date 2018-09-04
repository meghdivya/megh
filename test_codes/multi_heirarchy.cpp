#include<iostream>
using namespace std;

class A {
    public:
        A(){cout<<"A constructor called\n"<<endl;}
        ~A(){cout<<"A destructor called\n"<<endl;}
};

class B : virtual public A {
    public:
        B(){cout<<"B constructor called\n"<<endl;}
        ~B(){cout<<"B destructor called\n"<<endl;}
};

class C : virtual public A{
    public:
        C(){cout<<"C constructor called\n"<<endl;}
        ~C(){cout<<"C destructor called\n"<<endl;}
};

class D : public B, public C{
    public:
        D(){cout<<"D constructor called\n"<<endl;}
        ~D(){cout<<"D destructor called\n"<<endl;}
};


int main()
{
    D d;
    return 0;
}

