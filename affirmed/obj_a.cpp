
#include<stdio.h>

class B {
public:
B(int x) { printf("In constructor\n");}

};

class D: public B
{
};


int main()
{
	B* obj = new D();
	return 0;
}
