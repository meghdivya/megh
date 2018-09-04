#include<iostream>
#include<cstdlib>
#include "random.hpp"

using namespace std;
extern const int bss[];
int main()
{
    get_random(__LINE__);get_random(__LINE__);
    get_random(__LINE__);

    int arr[7] = {0};
    int i=1000;
    while(i--)
    {
        int random = rand()%6;
        arr[random]++;
        //cout<<random<<endl;

    }
#if 0
    cout<<"0 count"<<arr[0]<<endl;
    cout<<"1 count"<<arr[1]<<endl;
    cout<<"2 count"<<arr[2]<<endl;
    cout<<"3 count"<<arr[3]<<endl;
    cout<<"4 count"<<arr[4]<<endl;
    cout<<"5 count"<<arr[5]<<endl;
    cout<<"6 count"<<arr[6]<<endl;
#endif
    const int bss[] = {2,4,6,8,10,12,15};
    //int len = sizeof(bss)/sizeof(int);
    for(i=0;i<7;i++)
        arr[i]=0;
    i=50;
    while(i--)
    {
        cout<<bss[rand()%(sizeof(bss)/sizeof(int))]<<" ";
    }
    cout<<endl;
#if 0
    
    for(i=32;i<76;i++)
        cout<<i<<", ";

    cout<<endl;
    for(i=128;i<136;i++)
        cout<<i<<", ";

    cout<<endl;
    for(i=257;i< 270;i++)
        cout<<i<<", ";

    cout<<endl;
    for(i=0;i< 41;i++)
        cout<<i<<", ";

    //0-12, 32-75, 128-135
 #endif

    return 0;
}
