#include<iostream>
#include<vector>
using namespace std;
bool is_prime[1048576];
bool SieveOfEratosthenes(int n, bool isPrime[]) 
{ 
    // Initialize all entries of boolean array 
    // as true. A value in isPrime[i] will finally 
    // be false if i is Not a prime, else true 
    // bool isPrime[n+1]; 
    isPrime[0] = isPrime[1] = false; 
    for (int i=2; i<=n; i++) 
        isPrime[i] = true; 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If isPrime[p] is not changed, then it is 
        // a prime 
        if (isPrime[p] == true) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<=n; i += p) 
                isPrime[i] = false;

        } 
    } 
    for(int i=0; i<n; i++)
    {
        if(isPrime[i])
        {
            cout<<i<<", ";
        }
        cout<<endl;
    }
} 


int process_vector(vector<int>& v)
{
  //  for(auto const &value: v)
  //  {
  //      cout<<value<< " ";
  //  }
    int count = 0; 
    for(int i=0; i<v.size()-1; i++)
    {
        for(int j=i+1; j<v.size(); j++)
        {
            int XOR = v[i]^v[j];
            if(XOR%2==0 && XOR>2)
            {
                for(int k=2; k<XOR; k++)
                {
                    if(is_prime[k] && is_prime[XOR-k])
                    {
                        count++;
                        break;
                    }
                }
            }

        }
    }
    return count;
}
int main()
{
    SieveOfEratosthenes(1048576, is_prime);
    int T, N, Ai;
    cin>>T;
    vector<int> v;
    for(int i=0; i<T;i++)
    {
        cin>>N;
        for(int j=0; j<N; j++)
        {
            cin>>Ai;
            v.push_back(Ai);
        }
        cout<<process_vector(v)<<endl;
        v.clear();
    }
    return 0;
}
