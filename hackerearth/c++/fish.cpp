#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    int S;
    int E;
}fish;


struct compare_fish{
    bool operator()(fish& f1, fish& f2)
    {
        return f1.E < f2.S;
    }
};


int main() {
    int T,N,S,E;
    cin >> T;
    fish f;
    priority_queue<fish, vector<fish>, compare_fish> my_q;

    vector<fish> v;
    for(int i=0; i<T; i++)
    {
        cin >> N;
        for(int j=0; j<N; j++)
        {
            cin >> S >> E;
            f.S = S;
            f.E = E;
            my_q.push(f);
        }
    }
    while(!my_q.empty())
    {
        fish f = my_q.top();
        cout<<f.S << " " << f.E <<endl;
        my_q.pop();
    }
    return 0;
    
        // Writing output to STDOUT
}
