
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin>>T;
    int N,M,X,Y;
    vector<string> v;
    for(int i=0;i<T;i++)
    {
        cin>>N>>M>>X>>Y;
        if(((N-1)%X == 0) && ((M-1)%Y==0 ) && (N-1)>=0 && (M-1)>=0)
        {
            v.push_back("Chefirnemo");
        }
        else if( (N-2)%X == 0 && (M-2)%Y==0 && (M-2)>=0 && (N-2)>=0)
        {
            v.push_back("Chefirnemo");
        }
        else
        {
            v.push_back("Pofik");
        }
    }
    for(auto const& value: v)
        cout<<value<<endl;
    return 0;
}
