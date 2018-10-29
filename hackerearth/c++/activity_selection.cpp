#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct interval
{
    int start;
    int end;
}ivl;

bool cmp(const ivl& a, const ivl& b)
{
    if(a.start<b.start) return true;
    if(a.start==b.start) return (a.end<b.end);
    return false;
}

void choose_maximum_intervals(vector<ivl> &v, int alice, int bob)
{
    
}

int main()
{
    int T,N,si, ei;
    cin>>T;
    vector<ivl> v;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        for(int j=0; j<N; j++)
        {
            cin>>si>>ei;
            ivl t_ivl;
            t_ivl.start = si;
            t_ivl.end = ei;
            v.push_back(t_ivl);
        }

        sort(v.begin(), v.end(), cmp);
        choose_maximum_intervals(v, alice, bob);

        for(int i = 0; i<v.size(); i++)
        {
            cout<<"["<<v[i].start<<","<<v[i].end<<"]"<<endl;
        }
    }
    return 0;
}
