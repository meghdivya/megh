#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


void print_vector(vector<int>& v)
{
    for(int i=0; i<v.size(); i++)
        cout<<v[i] << " ";
}

int calculate_min_diff(vector<int>& v)
{
    int min = 1000002;
    for(int i=0; i<(v.size()-1); i++)
    {
        int diff = v[i+1] - v[i];
        if(diff < min)
        {
            min = diff;
        }
    }
    return min;
}

int main() {
    int T,N,v;
    cin>>T;
    vector<int> output;
    vector<int> input;
    for(int i =0; i<T; i++)
    {
        cin>>N;
        for(int j=0; j<N; j++)
        {
            cin>>v;
            input.push_back(v);
            //my_q.clear();
        }
        sort(input.begin(), input.end());
        //print_vector(input);
        output.push_back(calculate_min_diff(input));
        input.clear();

    }
    for(int i=0; i<output.size();i++)
        cout<<output[i]<<endl;

    return 0;
}
