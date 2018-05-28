#include <bits/stdc++.h>
	 
using namespace std;
	 
unsigned long long seed[2];
	 
const int MAX = 10;

int C[MAX][MAX];
int H[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int max_c,max_h;
		cin>>n>>max_c>>max_h;
	 
		for (int i=0;i<n;i++)
		{
			cin>>seed[0]>>seed[1];
		}
		
		for (int i=0;i<n;i++)
		{
			cin>>seed[0]>>seed[1];
		}
		
		cout<<'0';
		
		for(int i=1;i<n;i++)
		{
			cout<<'1';
		}
		cout<<endl;
	 
		for (int i=1;i<n;i++)
		{
			cout<<'1';
			for(int j=1;j<n;j++)
			{
				cout<<'0';
			}
			
			cout<<endl;
		}
	}
	return 0;
}