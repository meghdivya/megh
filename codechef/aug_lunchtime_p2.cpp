#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

typedef enum
{
    FINE = 1,
    WEAK = 2,
    INVALID = 3,
}result_e;

const char* output[] = {"","FINE", "WEAK", "INVALID"};


result_e process_correct(string &tc_bool)
{
    int i=0;
    while(i<tc_bool.size())
    {
        if(tc_bool[i++] == '0')
        {
            return INVALID;
        }
    }
    return FINE;
}

result_e process_wrong(string& tc_bool)
{
    int i=0;
    int j = 0;
    while(i<tc_bool.size())
    {
        if(tc_bool[i++] == '1')
        {
            j++;
        }
    }
    if(tc_bool.size() == j)
        return WEAK;
    return FINE;
}

int main()
{
    int T,N,M;
    //pair<string, string> p1;
    //vector<pair<string, string> v;
    cin>>T;
    vector<string> stored_op;
    for(int i=0;i<T; i++)
    {
        //result_e result = FINE;
        result_e final_wrong_result = FINE;
        result_e final_correct_result = FINE;
        cin >> N >> M;
        //cout<<"T= "<<T<<",N = "<<N<<", M = "<<M<<endl;
        string result_str, tc_bool; 
        for(int j=0; j<N; j++)
        {
            cin >> result_str >> tc_bool;
            //cout<<result_str << " " << tc_bool<<endl;
            if(result_str == "correct")
            {
                //result = ;
                if(process_correct(tc_bool) == INVALID)
                {
                    final_correct_result = INVALID;
                }
            }
            else if(result_str == "wrong")
            {
                //result = ;
                if(process_wrong(tc_bool) == WEAK)
                {
                    final_wrong_result = WEAK;
                }
            }

        }
        if(final_correct_result == INVALID)
        {
            stored_op.push_back(output[INVALID]);
        }
        else if(final_correct_result == FINE && final_wrong_result == FINE)
        {
            stored_op.push_back(output[FINE]);
        }
        else if(final_correct_result == FINE && final_wrong_result == WEAK)
        {
            stored_op.push_back(output[WEAK]);
        }
    }
    for(int i=0; i<stored_op.size(); i++)
        cout<<stored_op[i]<<endl;
    return 0;
}
