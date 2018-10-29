#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
#if 0
    map<string, int> test;
    for(int i=0; i<10;i++)
        test.insert(pair<string,int> ("test-str" + to_string(i), i));

    for(auto itr = test.begin(); itr!=test.end(); ++itr)
        cout<<'\t'<<itr->first<<'\t'<<itr->second<<'\n';

    test.erase("test-str1");
    test["test-str100"] = 100;
    test["test-str1"] = 101;
    test["test-str2"] = 200;
    for(auto itr = test.begin(); itr!=test.end(); ++itr)
        cout<<'\t'<<itr->first<<'\t'<<itr->second<<'\n';

#endif
    unordered_map<string, int> test2;
    for(int i=0; i<10;i++)
        test2.insert(pair<string,int> ("test-str" + to_string(i), i));

    for(auto itr = test2.begin(); itr!=test2.end(); ++itr)
        cout<<'\t'<<itr->first<<'\t'<<itr->second<<'\n';

    test2["test-str100"] = 100;
    test2["test-str1"] = 101;
    test2["test-str2"] = 200;
    for(auto itr = test2.begin(); itr!=test2.end(); ++itr)
        cout<<'\t'<<itr->first<<'\t'<<itr->second<<'\n';
    unordered_map<string, int>::iterator it;
    it= test2.find("test-str2");

    if(it!=test2.end())
        printf("found");

    cout<<test2.size()<<endl;
    cout<<"*****************\n"<<endl;
    auto test_moved = move(test2);
    cout<<test2.size()<<endl;
    cout<<"*****************\n"<<endl;
    cout<<test_moved.size()<<endl;

    return 0;
}
