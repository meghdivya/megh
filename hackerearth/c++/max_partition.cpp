#include<iostream>
#include<vector>
#include<map>
using namespace std;


int minimize_K(int K)
{
    if(K>300)
        return 300;
    return K;
}

int calculate_strength(vector<int> v)
{
    map<int, int>m1;
    map<int,int>::iterator map_it;
    int largest = 0;
    for(auto it=v.begin(); it!= v.end(); ++it)
    {
        map_it = m1.find(*it);
        if(map_it == m1.end())
        {
            m1.insert(pair<int,int> (*it, 1));
        }
        else
        {
            map_it->second++;
        }
    }
    map_it=m1.begin();
    while(map_it!=m1.end())
    {
        if(1 == (map_it->second)%2)
        {
            if(largest<map_it->first)
                largest = map_it->first;
        }
        ++map_it;
    }
    return largest;
}

long calculate_all_partition(vector<int>v, int i, int j, int k)
{
#if 0
    long sum = 0;
//    vector<int>v1;
    int script = k;
    while(script)
    {
        vector<int>::const_iterator first = v.begin() + i;
        vector<int>::const_iterator last = v.begin() + j;
        vector<int> v1(first, last);


    }
#endif

}

void partition(vector<int> v,int k)
{
#if 0
    int i = 1;
    for(;i<=k; ++i)
    {
        if(i==1)
        {
            cout<<calculate_strength(v);
        }
        else
        {

        }
    }
#endif
}

int main()
{
    int T;
    int n,i,k,array_e;
    cin>>T;
    vector<int> v;
    vector<int> output;
    i=0;

    while(i<T)
    {
        cin>>n;
        cin>>k;
        for(int j=0;j<n;j++)
        {
            cin>>array_e;
            v.push_back(array_e);
        }
        cout<<calculate_strength(v)<<endl;
    }

}
