#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin>>T;
    int N,X,S,A,B,gold;
    vector<int> output;
    for(int i=0;i<T;i++)
    {
        cin>>N>>X>>S;
        gold = X;
        for(int j=0; j<S; j++)
        {
            cin>>A>>B;
            if(A==gold)
            {
                gold = B;
            }
            else if(B== gold)
            {
                gold = A;
            }
        }
        output.push_back(gold);
    }
    for(auto const& value: output)
        cout<<value<<endl;
    return 0;
}
