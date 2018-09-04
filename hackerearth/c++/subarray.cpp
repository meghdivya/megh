#include<iostream>
#include<vector>
using namespace std;


int find_max_sub_len(vector<unsigned int> v)
{
    int len = v.size();
    int i=0, j= len-1;
    int start = i, end =j;
    int max = 0,max_so_far =0;
    while(start<end)
    {
        i=start;
        j= end;
        for(; i<j; i++)
        {
            if(v[i]>=v[j])
            {
                max= j-i+1;
                if(max>max_so_far)
                {
                    max_so_far=max;
                }
                break;
            }

        }
        end--;
    }
    
    if(max_so_far == 0)
        return 1;
    return max_so_far;
}

int main()
{
    int T;
    int n,i,array_e;
    cin>>T;
    vector<unsigned int> v;
    vector<int> output;
    i=0;

    while(i<T)
    {
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>array_e;
            v.push_back(array_e);
        }
        output.push_back(find_max_sub_len(v));
        v.clear();
        i++;
    }
    for(auto it= output.begin(); it!=output.end();++it)
        cout<<*it<<endl;

}
