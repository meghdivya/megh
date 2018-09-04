#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    int arr[26] = {0};
    int num; string s;
    int max = 0;
    cin >> num;                                     // Reading input from STDIN
    cin >> s;
    for(int i = 0; i<num; i++)
    {
        ++arr[s[i]-97];
        if(arr[s[i]-97] > max)
            max = arr[s[i]-97];
    }
    cout<<(num-max)<<endl;
    return 0;
            // Writing output to STDOUT
}
