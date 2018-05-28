#include <iostream>
#include <bits/stdc++.h>
	 
using namespace std;
	 
#define ll long long int
	 
int main()
{
	int t;
	cin>>t;
	 
	while(t--)
	{
		ll n,z,x,y;
		cin>>n;
	 
		vector<ll> v[n+2];
		vector<ll> dp[n+2];
		
		for(int i=0;i<n;i++)
		{
			cin>>z;
	 
			for(ll j=0;j<z;j++)
			{
				cin>>x;
				v[i].push_back(x);
				dp[i].push_back(0);
			}
		}
	 
		if(n==2)
		{
			sort(v[0].begin(),v[0].end());
			sort(v[1].begin(),v[1].end());
			
			cout<<max(v[1][v[1].size()-1]-v[0][0],v[0][v[0].size()-1]-v[1][0])<<endl;
			continue;
		}
		for(int i=0;i<v[1].size();i++)
		{
			for(ll j=0;j<v[0].size();j++)
			{
				dp[1][i]=max(dp[1][i],abs(v[1][i]-v[0][j]));
	 
			}
		}
	 
		for(int i=2;i<n;i++)
		{
			for(ll j=0;j<v[i].size();j++)
			{
				for(ll k=0;k<v[i-1].size();k++)
				{
					if(k+1==v[i-1].size())
					{
						dp[i][j]=max(dp[i][j],abs(v[i][j]-v[i-1][k])*i+dp[i-1][0]);
					}
					else
					{
						dp[i][j]=max(dp[i][j],abs(v[i][j]-v[i-1][k])*i+dp[i-1][k+1]);
					}
				}
			}
		}
		
		ll ans=-1;
		
		for(int i=0;i<v[n-1].size();i++)
		{
			ans=max(ans,dp[n-1][i]);
		}
	 
		cout<<ans<<endl;
	}
	 
	return 0;
}