#include <iostream>
#include <bits/stdc++.h>
using namespace std;
	 
#define ll long long
int main()
{
	ll t,i;
	ll kCoin=0;
	
	cin>>t;
	while(t--)
	{
		ll u,v,w;
		cin>>u>>v;
		n = u+v;
		
		
		if(w%2==0)
		{
			kCoin = w/2;
			kCoin = kCoin*(w+1);
			kCoin++;
			
			
			
		}
	 
		else
		{
			kCoin = (w+1)/2;
			kCoin = kCoin*w;
			kCoin++;
		}
		
		
		for(i=0;i<u;i++)
		{
			kCoin+=1;
		}
		
		cout<<kCoin<<endl;
	}
	
	
	return 0;
}