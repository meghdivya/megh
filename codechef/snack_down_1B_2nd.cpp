#include<iostream>
using namespace std;

int main()
{
    int T, N, K;
    cin >> T;
    for(int i = 0; i<T; i++)
    {
        cin>>N>>K;
        int ai;
        int num_of_1s = 0;
        for(int j=0 ;j<N; j++)
        {
            cin >> ai;
            if(ai == 1)
            {
                ++num_of_1s;
            }
        }
        if(N-num_of_1s> K)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
    }
    return 0;
}
