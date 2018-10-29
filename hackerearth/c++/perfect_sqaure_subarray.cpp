#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
} 


int main()
{
    int N, ai;
    cin>>N;
    vector<int> v;
    
    int ans = 0;
    for(int i=0; i<N; i++)
    {
        cin>>ai;
        v.push_back(ai);
    }
    for (int a = 0; a < N; a++) {
        int sum = 0;
        for (int b = a; b <N; b++) {
            sum += v[b];
            if(isPerfectSquare(sum))
            {
                ++ans;
            }
        }
    }
    cout<<ans<<endl;
}
