#include<iostream>
#include<string>
using namespace std;

int next_palindrome(int& num)
{
    cout<<"Input = "<<num<<endl;
    string num_str = to_string(num);
    string tmp_str;
    tmp_str = num_str;
    int pre_index = 0;
    int post_index = num_str.size();
    while(pre_index<post_index)
    {
        if(num_str[pre_index] == num_str[post_index] && num_str[pre_index]!='9')
        {
            continue;
        }
        else if()
        {
        }
    }
}

int main()
{
    int num;
    cin>>num;
    cout<<next_palindrome(num)<<endl;
    return 0;
}
