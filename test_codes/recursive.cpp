#include<iostream>
using namespace std;

int add(int* arr, int len) {
    if(len == 0) return 0;
    return add(arr, len-1) + arr[len-1];
}
int main() {
    int arr[] = {1,2,3,4};
    int len=4;
    cout<<add(arr, len)<<endl;
    cout<< len<<endl;
}
