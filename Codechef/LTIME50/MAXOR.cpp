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
		int arr[n];
		int i;
		for(i=0;i<n;i++)cin>>arr[i];
			
			int j;
		long long int count=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if((arr[i]|arr[j])<=max(arr[i],arr[j]))
				{
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}