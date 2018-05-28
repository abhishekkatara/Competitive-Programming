#include <iostream>
#include <bits/stdc++.h>
#define lld long long int
	 
using namespace std;
	 
	 
lld a[100001],b[701],y,k;
	 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lld c;
	for(lld i=1;i<100001;i++)
	{
		a[i] = i*i;
		if(i<701)
			b[i] = i;
	}
	int t;
	cin>>t;
	 
	while(t--)
	{
		c=0;
		cin>>y;
		for(lld i=1;i<100001;i++)
		{
			k = y-a[i];
			if(k<=700 && k>=1)
				c+=k;
			else if(k>700)
				c+=700;
		}
		cout<<c<<endl;
	}
	return 0;
}