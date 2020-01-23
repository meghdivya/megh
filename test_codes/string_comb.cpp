#include<iostream>
#include<vector>
#include<set>
using namespace std;

void print_partial(set<int> &partial) {
    cout<<"p<";
    for(auto it=partial.begin(); it!=partial.end(); ++it)
        cout<<(*it);
    cout<<">\n";
}
void print_start_comb(vector<int> &ip, set<int> &partial, int start, int K) {
    //cout<<__LINE__<<start<<K<<endl;
    cout<<"start = "<<start<<", ";
    print_partial(partial);
    if(K == partial.size()) {
        cout<<"Final answer -->";
        print_partial(partial);
        return;
    }
    if(start == ip.size()) { 
        cout<< "returning for start == ip.size()"<<endl; 
        return;
    }
    for(int i=start; i<ip.size(); ++i)
    {
        partial.insert(ip[i]);
        print_start_comb(ip, partial, i+1, K);
        partial.erase(ip[i]);
    }
}

int main() {
    vector<int> ip{5,6,7,8,9};
    cout<<ip.size()<<endl;
    set<int> partial;
    print_start_comb(ip, partial, 0, 4);
    return 0;
}
