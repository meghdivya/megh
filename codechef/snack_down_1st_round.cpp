#include<iostream>
#include<utility>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;


int main()
{
    int T,N,K,team_score;
    cin>>T;
    int count = 0;
    vector<int> op;
    for(int i=0; i<T; i++)
    {
        priority_queue<int> pq;
        cin>>N>>K;
        for(int j=0; j<N; j++)
        {
            cin>>team_score;
            pq.push(team_score);
        }
        while(count<K)
        {
            int top = pq.top();
            pq.pop();
            if(count == K-1)
            {
                while(top == pq.top())
                {
                    count++;
                    pq.pop();
                }
            }
            else if(count>=K)
                break;
            count++;
        }
        op.push_back(count);
        count = 0;
    }
    for(int i = 0; i<op.size(); i++)
        cout<<op[i]<<endl;
    return 0;

}
