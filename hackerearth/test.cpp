#include<iostream>
using namespace std;

class A{
  public: 
    int x;
    public:
   A(int xx): x(xx){}
   A(const A& a) { x = a.x; x++;}
  void operator = (const A& a1) { x= a1.x; x--;}
};


int main()
{
A a(4);
A b = a;
//cout<<b.x<<endl;
char ab[] ="abcde";
cout<<sizeof(ab)<<endl;
return 0;
}
