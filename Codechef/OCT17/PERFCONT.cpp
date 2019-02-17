#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		lld n,p;
		
		cin>>n>>p;
		
		lld t1 = p/2 ;
		lld t2 = p/10;
		lld h1 = 0;
		lld h2 = 0;
	 
		lld arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			
			if(arr[i]>=t1) { h1++; }
	 
			else if(arr[i]<=t2) { h2++; }
		}
		if(h1==1 && h2==2) { cout << "yes" << endl; }
		else { cout << "no" << endl; }
	}
	return 0;
}