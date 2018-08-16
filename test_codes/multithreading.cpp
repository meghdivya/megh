#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

static int i = 0;
class Fctor{
    mutex m1;
public:
    void operator()(){
        unique_lock<mutex> mlock(m2);
        i++;
        cout<<"from thread  "<<this_thread::get_id()<<","<<i<<endl;
    }
};

int main()
{
    Fctor fct;
    thread t1(fct);//,t1.get_id()); 
    thread t2(fct);//;,t2.get_id()); 

    t1.join();
    t2.join();
    return 0;
}
