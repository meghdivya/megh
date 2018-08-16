
#include<iostream>
using namespace std;

int is_equilb(int *arr, int n)
{
    int i = 0;
    int j = n-1;
    int sum_p =0, sum_s =0;
    if(i==j)
        return 1;
    while(i<j)
    {
        sum_p = sum_p + arr[i++];
        sum_s = sum_s + arr[j--];
        if((sum_p == sum_s) && ((j-i) == 2))
            return i+2;
        
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,2,1};
    int arr1[] = {1};
    int arr2[] = {1,2,3,4,5};
    int arr3[] = {1,2,3,4,2,1};
    cout<<is_equilb(arr, 5)<<endl;;
    cout<<is_equilb(arr1, 1)<<endl;;
    cout<<is_equilb(arr2, 5)<<endl;;
    cout<<is_equilb(arr3, 6)<<endl;;
    return 0;
}
