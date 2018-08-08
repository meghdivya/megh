#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

// Complete twins function
// DO NOT MODIFY anything outside the below function
vector<string> twins(const vector<string>& a, const vector<string>& b) {
    vector<string> res;
    const int MAX_CHAR = 26;
    int a_size=0,b_size=0,i=0,j=0,min = 0;
    int a_even_hash[MAX_CHAR] ={0};
    int a_odd_hash[MAX_CHAR] = {0};
    int b_even_hash[MAX_CHAR] = {0};
    int b_odd_hash[MAX_CHAR] = {0};
    vector<string>::iterator it_a;
    vector<string>::iterator it_b;
    
    a_size=a.size();
    b_size=b.size();
    int min_size = a_size;
    if(a_size>b_size)
        min_size = b_size;
    res.reserve(min_size);
    for(; j<a_size && j<b_size; ++j)
    {
        string ele_a = a[j]; 
        string ele_b = b[j];
        int len_a = ele_a.length();
        int len_b = ele_b.length();

        while(i<len_a)
        {
            if(i&1)
            {
                ++a_odd_hash[ele_a[i]-'a'];
            }
            else
            {
                ++a_even_hash[ele_a[i]-'a'];
            }
            ++i;
        }
        i = 0;
        while(i<len_b)
        {
            if(i&1)
            {
                b_odd_hash[ele_b[i]-'a']++;
            }
            else
            {
               b_even_hash[ele_b[i]-'a']++;
            }
            ++i;
        }
        i=0;
        string encode_a="", encode_b="";
        ostringstream convert;   // stream used for the conversion
        string result_odd,result_even;
        //Can do to_string if C++11 is there
        for(;i<MAX_CHAR;i++)
        {
            convert.str("");
            convert<<a_even_hash[i];
            result_odd = convert.str();
            convert.str("");
            convert <<a_odd_hash[i];
            result_even = convert.str();
            encode_a = encode_a + result_odd + "-" +  result_even + "-";

            convert.str("");
            convert<<b_even_hash[i];
            result_odd = convert.str();
            convert.str("");
            convert <<b_odd_hash[i];
            result_even = convert.str();
            encode_b = encode_b + result_odd + "-" +  result_even + "-";
        }
        cout<<encode_a<<endl;
        cout<<encode_b<<endl;
        if(encode_a == encode_b)
            res.push_back("Yes");
        else
            res.push_back("No");

        i=0;
        for(;i<MAX_CHAR;i++)
        {
            a_odd_hash[i]=0;
            b_odd_hash[i]=0;
            a_even_hash[i]=0;
            b_even_hash[i]=0;
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
