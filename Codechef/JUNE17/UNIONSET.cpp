#include <iostream>
#include <bits/stdc++.h>
	 
using namespace std;
	 
#define ll long long
ll lenAr[10009];
vector<ll> numSet[10009];
ll num,k;
ll pairCheck(ll x, ll y)
{
	ll X=0,Y=0,ret;
	for (ll i=1;i<=k;i++)
	{
		ll flag = 0;
		if(X<numSet[x].size()&&numSet[x][X]==i)
		{
			X++;
			flag = 1;
		}
		
		if(Y<numSet[y].size()&&numSet[y][Y]==i)
		{
			Y++;
			flag = 1;
		}
		
		if(flag==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll n,result=0;
		cin>>n>>k;
		for (ll i=1;i<=n;i++)
		{
			numSet[i] = vector<ll>();
			scanf("%lld", &lenAr[i]);
			for (ll j=1;j<=lenAr[i];j++)
			{
				scanf("%lld", &num);
				numSet[i].push_back(num);
			}
			sort(numSet[i].begin(), numSet[i].end());
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(lenAr[i]+lenAr[j]<k)
				{
					continue;
				}
				result += pairCheck(i,j);
			}
		}
		cout<<result<<endl;
	}
	return 0;
}