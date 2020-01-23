#include <iostream>
#include <vector>

using namespace std;
void print_anagram(string &s, string& partial, int k) {
    if(k==s.size()) {
        cout<<partial<<endl;
    }
    for(int i=0; i<s.size(); ++i)
    {
        partial[i] = s[i];
        print_anagram(s, partial, k+1);
        partial[i] = ' ';
    }

}

int main() {
    string s;
    cin>>s;
    cout<<s;
    vector<char> v;
    string partial = s;
    for(int i=0; i<partial.size(); ++i)
        s[i] = ' ';
    print_anagram(s, partial, 0);
}
