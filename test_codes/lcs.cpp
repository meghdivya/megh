#include<iostream>
using namespace std;
int max(int a, int b)
{
	return a>b?a:b;
}

int lcs(string s1, string s2)
{
	int n = s1.size();
	int m = s2.size();
	if(!n || !m)
		return 0;

	int c[n+1][m+1];
	for(int i=0; i<n+1 ; ++i)
	{
		for(int j=0; j<m+1; ++j)
		{
			c[i][j]=0;
		}
	}

	for(int i=0; i<n ; ++i)
	{
		for(int j=0; j<m; ++j)
		{
			if(s1[i] == s2[j])
			{
				c[i+1][j+1] = 1 + c[i][j];
			}
			else
			{
				c[i+1][j+1] = max(c[i+1][j], c[i][j+1]);
			}
		}

	}
	return c[n][m];
}

int main()
{
	string s1,s2;
	cout<<"Enter 2 string"<<endl;
	cin>>s1>>s2;
	cout<<lcs(s1,s2);
	return 0;
}
