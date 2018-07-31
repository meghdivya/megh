#include<iostream>
using namespace std;

int get_last_bit_set_position(int num)
{
    int last_bit_pos = 0;
    while(num)
    {
        if(num%2 == 1)
        {
            return ++last_bit_pos;
        }
        ++last_bit_pos;
        num >>= 1;
    }
}

int get_last_bit_set_position_optimize(int num)
{

}

int main()
{
    int i;
    while(1)
    {
        cout<<"Enter a number to get last bit set or -1 to exit\n";
        cin>>i;
        if(i==-1)
            return 0;
        cout<<get_last_bit_set_position(i) << endl;
    }
    return 0;
}

