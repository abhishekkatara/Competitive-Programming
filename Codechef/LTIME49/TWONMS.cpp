#include <iostream>
#include <bits/stdc++.h>

using namespace std;
	 
long long int min(long long int a,long long int b)
{
	if(a<b)
		return a;
	
	else
		return b;
}
	 
long long int max(long long int a,long long int b)
{
	if(a>b)
		return a;
	
	else
		return b;
	
}

int main()
{
	int t;
	cin >>t;
	while(t--)
	{
		long long int a,b,n;
		cin>>a>>b>>n;
		if(n%2==1)
		{
			a*=2;
		}
		cout<<max(a,b)/min(a,b)<<endl;
	}
	return 0;
}