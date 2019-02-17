#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MOD 1000000007

int ma[64][20];
ll ans(ll arr1[],ll arr2[])
{
	ll i,temp=0;
	for(int i=0;i<=25;i++)
		temp+=arr1[i]*arr2[i];
	return temp;
}
int main()
{
	ll arr[64];
	arr[0]=1;
	int i;
	for(int i=1;i<64;i++)
	{
		arr[i]=arr[i-1]*2;
	}
	
	int t;
	cin>>t;
	 
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		ll ans=0;
		
		while(k>0)
		{
			if(k%2==0)
			{
				k=k/2;
				n--;
			}
			else
			{
				ans+=arr[n-1];
				k=k/2;
				n--;
			}
		}
		cout<<ans<<endl;
		
	}
}