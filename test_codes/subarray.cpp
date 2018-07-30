#include<iostream>
using namespace std;

void print_arr(int* arr, int arr_size)
{
    int i = 0;
    for(;i<arr_size; i++)
        cout << arr[i] << " ";
    return;
}

int maximum_subarr(int* arr, int arr_size, int subarr_size)
{
    if(subarr_size > arr_size)
    {
        cout << "invalid subarray size\n";
        return 0;
    }
    else
    {
        int cost_sub_arr = 0,k = 0,i = 0;
        for(; i<subarr_size; i++)
            cost_sub_arr += arr[i];

        cout<< "i = "<< i <<",k = " <<k << endl;

        while(i<arr_size)
        {
            if(cost_sub_arr < (cost_sub_arr + arr[i] - arr[k]))
            {
                cost_sub_arr = cost_sub_arr + arr[i] - arr[k];
            }
            ++k;
            ++i;
        }
        return cost_sub_arr;
    }
}

int main()
{
	int length,i = 0;
    int num = 0;
    cout<< "Enter the length of the array\n";
    cin >> length;
    int arr_length = length;
	int arr[length];
    cout<< "Enter "<< length <<" numbers for array\n";
    while(length)
    {
        cin >> num;
        arr[i] = num;
        ++i;
        --length;
    }
    cout<< "Enter the subarray size \n";
    cin >> length;
    //print_arr(arr, arr_length);
    cout<< "The maximum subarray cost = " << maximum_subarr(arr, arr_length, length) << endl;
    return 0;
}
