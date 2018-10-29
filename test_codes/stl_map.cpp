#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    map<string, int>m1;
    for(int i =0;i <10; i++)
        m1.insert(pair<string, int> ("a"+to_string(i),i));

    for(auto it=m1.begin();it!=m1.end();++it)
        cout<<it->first<<","<<it->second<<endl;

    cout<<m1.size()<<endl;

    map<string, int>::iterator it = m1.find("a11");
        if(it != m1.end())
            cout<<it->first<<","<<it->second<<","<<(it->first).size()<<endl;
        else
            cout<<"not found"<<endl;

   unordered_map<string, int>m2;
   for(int i =0;i <10; i++)
        m2.insert(pair<string, int> ("a"+to_string(i),i));
   m2["hello"] = 111;
   for(const auto &v: m2)
   {
            cout<<v.first<<","<<v.second<<","<<(v.first).size()<<endl;
   }

}
