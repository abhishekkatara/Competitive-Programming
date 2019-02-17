#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
	 
using namespace std;
#define ll long long
	 
int main()
{
	int t;
	ll e,p,k,x,z,s;
	cin>>t;
	
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		ll arr[n];
	 
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}
	 
		for(ll i=1;i<=q;i++)
		{
			ll a,b,c,d;
			cin>>a>>b>>c>>d;
	 
			e=b-a+1;
			ll temp1[e];
			ll temp2[e];
			p=0;
			for(ll k=a-1;k<=b-1;k++)
			{
				temp1[p]=arr[k];
				p++;
			}
			
			sort(temp1,temp1+e);
			x=0;
			
			for(ll m=c-1;m<=d-1;m++)
			{
				temp2[x]=arr[m];
				x++;
			}
			sort(temp2,temp2+e);
			ll count=0;
	 
			for(ll n=0;n<e;n++)
			{
				if(temp1[n]!=temp2[n])
					count=count+1;
			}
			if(count<=1)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}