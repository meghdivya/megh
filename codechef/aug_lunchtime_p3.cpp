#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int T;
    cin>>T;
    int N,Z1,Z2;
    vector<int> v;
    vector<int> output;
    for(int i=0;i<T;i++)
    {
        cin>>N>>Z1>>Z2;
        int Ai;
        for(int j=0;j<N;j++)
        {
            cin>>Ai;
            v.push_back(Ai);
        }
        
        if(v.size() <= 2)
        {
            if(v.size()==1) v.push_back(0);
            //cout<<abs(v[0]+v[1])<<endl;
            if(abs(v[0]) == abs(Z1) ||abs(v[1]) == abs(Z1) ||abs(v[1]) == abs(Z2)|| abs(v[0]) == abs(Z2))
            {
                output.push_back(1);
            }
            else if(abs(v[0]+v[1]) == abs(Z1) || abs(v[0]+v[1]) == abs(Z2)|| abs(v[0] - v[1]) == abs(Z2)|| abs(v[0] - v[1]) == abs(Z1) ||
                    abs(2*v[0]) == abs(Z1) || abs(2*v[0]) == abs(Z2)|| abs(2*v[1]) == abs(Z1) || abs(2*v[2]) == abs(Z2))
            {
                output.push_back(2);
            }
            else
            {
                output.push_back(0);
            }
        }
        for(int i=0; i<output.size(); i++)
            cout<<output[i]<<endl;
    }
    return 0;
}
