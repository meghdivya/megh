
#include <iostream>
#include<vector>
#include<cmath>

using namespace std;

int perform_Q1(vector<int>& v, int X, int LV)
{
    return v[(1<<(LV-1))+X-1];
}
int perform_Q2(vector<int>& v, int L, int R)
{
    int level_l_first_index = 1<<(L-1);
    int level_R_last_index = 1<<R;

    int i, sum=0;
    for(i=level_l_first_index; i<level_R_last_index && i<v.size(); i++)
    {
        sum+= v[i];
    }

    return sum;
}
void perform_Q3(vector<int>& v, int X, int LV, int VAL)
{
    v[(1<<(LV-1))+X-1] = VAL;
}

int main() {
    int N,Q, query_type;
    int i=0;
    cin>>N;
    cin>>Q;
    int node;
    vector<int> tree_nodes;
    vector<int> output;
    tree_nodes.push_back(0);
    for(i=0; i<N; i++)
    {
        cin>>node;
        tree_nodes.push_back(node);
    }
    for(i=0; i<Q; i++)
    {
        cin>>query_type;
        switch(query_type)
        {
            case 1:
            {
                int X,LV;
                cin>>X;
                cin>>LV;
                output.push_back(perform_Q1(tree_nodes, X, LV));

            }break;
            case 2:
            {
                int L,R;
                cin>>L;
                cin>>R;
                output.push_back(perform_Q2(tree_nodes, L, R));

            }break;
            case 3:
            {
                int X,LV, VAL;
                cin>>X;
                cin>>LV;
                cin>>VAL;
                perform_Q3(tree_nodes, X, LV, VAL);

            }break;
        }
    }
    for(i=0;i<output.size();i++)
        cout<<output[i]<<endl;
}

