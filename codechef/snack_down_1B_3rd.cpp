#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

#define MODULO_NUMBER 1000000007

int main()
{
    int T,N,K;
    cin >> T;
    for(int i = 0; i<T; i++)
    {
        cin>>N>>K;
        //float max_k = (sqrt((8*(float)N)  + (float)1) /(float)2) - (float)0.5;
        int max_k_int = K*(K+1)/2;
        //printf("%f,%d\n", max_k, max_k_int);
         
        if(N < max_k_int)
        {
            printf("-1\n");
        }
        else
        {
            if(N < (max_k_int + K))
            {
                printf("0\n");
            }
            else
            {
                if(K==1)
                {
                    unsigned long long product = N*(N-1);
                    printf("%llu\n", product%MODULO_NUMBER);
                    continue;
                }
                vector<int> v;
                double n_by_k = (double)N/(double)K;
                int integral = (int)n_by_k;
                float fraction = n_by_k - integral;
                if(fraction >= 0.5)
                {
                    integral = integral + 1;
                }
                int adjustment = N - (K*integral);
                int index = 1;
                int j = index;
                for(; index<K; )
                {
                    v.push_back(integral + j);
                    v.push_back(integral - j);
                    index = index + 2; ++j;
                }
                sort(v.begin(), v.end());
                bool adjusted = false;
                unsigned long long product = 1;
                for(int z=0; z<v.size();z++)
                {
                    if(!adjusted)
                    {
                        int temp = v[z] + adjustment;
                        if(temp > 1 && !binary_search(v.begin(), v.end(), temp))
                        {
                            v[z] = temp;
                            adjusted = true;
                        }
                    }
                    product = (product * v[z] * (v[z] -1)) % MODULO_NUMBER;
                    printf("%d -> ", v[z]);
                }
                printf("%llu\n", product);
            }
        }

    }
    return 0;
}
