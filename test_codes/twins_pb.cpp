
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Complete twins function
// DO NOT MODIFY anything outside the below function
bool is_twin(const string& a_str, const string& b_str)
{
    int i = 0;
    int* a_freq = (int*)calloc(52, sizeof(int));
    int* b_freq = (int*)calloc(52, sizeof(int));
    for(i = 0; (i+1) < a_str.size(); i += 2) {
        a_freq[a_str[i] - 'a']++;
        b_freq[b_str[i] - 'a']++;
        a_freq[26 + a_str[i+1] - 'a']++;
        b_freq[26 + b_str[i+1] - 'a']++;
    }
    if(i < a_str.size()) {
        a_freq[a_str[i] - 'a']++;
        b_freq[b_str[i] - 'a']++;
    }
    for(int j = 0; j < 52; j++) {
        if(a_freq[j] != b_freq[j]) {
            return false;
        }
    }
    return true;
}

vector<string> twins(const vector<string>& a, const vector<string>& b) {
    vector<string> res;
    res.reserve(a.size());
    for(int i = 0; i < a.size(); i++) {
        if(a[i].size() == b[i].size()) {
            if(is_twin(a[i], b[i])) {
                res.push_back("Yes");
            } else {
                res.push_back("No");
            }
        } else {
            res.push_back("No");
        }
    }
    
    return res;
}
// DO NOT MODIFY anything outside the above function

int main() {

    /* Read input from STDIN. Print output to STDOUT */
    vector<std::string> a, b;
    int aSize, bSize;

    cin >> aSize;
    a.reserve(aSize);
    string s;
    for (int i = 0; i < aSize; ++i) {
        cin >> s;
        a.push_back(s);
    }

    cin >> bSize;
    b.reserve(bSize);
    for (int i = 0; i < bSize; ++i) {
        cin >> s;
        b.push_back(s);
    }

    // call twins method
    vector<string> res = twins(a, b);

    for (vector<string>::iterator it = res.begin(); it != res.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}

