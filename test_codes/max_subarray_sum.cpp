#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n;i++)
	{
		cin>>a[i];
	}
	int max_so_far = a[0];
	int curr_max = a[0];
	for(int i=1; i<n; i++)
	{
		curr_max = max(a[i], curr_max+a[i]);
		max_so_far = max(max_so_far, curr_max);
		cout<<"curr-max = "<<curr_max<<", max_so_far = "<<max_so_far<<endl;
	}
        cout<<max_so_far;
	return 0;
}
