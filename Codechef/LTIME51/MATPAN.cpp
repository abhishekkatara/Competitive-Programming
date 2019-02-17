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
		int arr[26];
		lld ans=0;
		for(int i=0;i<26;i++)
		{
			cin >> arr[i];
			ans+=arr[i];
		}
		
		string str;
		cin>>str;
	 
		for(i=0;i<str.length();i++)
		{
			if(arr[str[i]-'a']!=0)
			{
				ans-=arr[str[i]-'a'];
				arr[str[i]-'a']=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}