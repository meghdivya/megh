
#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string, int> test;
    for(int i=0; i<10;i++)
        test.insert(pair<string,int> ("test-str" + to_string(i), i));

    for(auto itr = test.begin(); itr!=test.end(); ++itr)
        cout<<'\t'<<itr->first<<'\t'<<itr->second<<'\n';

    test.erase("test-str1");
    for(auto itr = test.begin(); itr!=test.end(); ++itr)
        cout<<'\t'<<itr->first<<'\t'<<itr->second<<'\n';

    return 0;
}
