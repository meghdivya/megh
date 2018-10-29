#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int T,N,ai;
    cin >>T;
    vector<int> v;
    bool connected = true;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        for(int i=0; i<N; i++)
        {
            cin>>ai;
            v.push_back(ai);
        }
        int j =0;
        for(int i=0; i<v.size()-1; i++)
        {
            for(j = i+1; j<v.size();j++)
            {
                if(__gcd(v[i], v[j]) == 1)
                {
                    break;
                }
            }
            if(j == v.size())
            {
                connected = false;
                break;
            }
        }
        int count_forty_seven = 0;
        for(int z = 0; z<v.size(); z++)
        {
            if(v[z] == 47)
            {
                count_forty_seven++;
            }
        }
        if(count_forty_seven == v.size() -1)
        {
            connected = true;
        }
        if(connected)
        {
            cout<<"0"<<endl;
            for(int i=0; i<v.size(); i++)
                cout<<v[i]<<" ";
        }
        else
        {
            cout<<"1"<<endl;
            if(v[0] !=47)
            {
                v[0] = 47;
            }
            else
            {
                v[0] = 2;
            }
            for(int i=0; i<v.size(); i++)
                cout<<v[i]<<" ";
        }
        v.clear();
    }
    return 0;
}
