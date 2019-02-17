#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;

		if(n==1)
		{
			cout<<1<<endl;
		}

		else if(n&1==1)
		{
			int sum = (n-1)-(n/2);
			while(n--)
			{
				cout<<sum<<" ";
				sum++;
			}
			cout<<endl;
		}

		else
		{
			int sum=n/2;

			while(n--)
			{
				cout<<sum<<" ";
				sum++;
			}
			cout<<endl;
		}
	}
	return 0;
}