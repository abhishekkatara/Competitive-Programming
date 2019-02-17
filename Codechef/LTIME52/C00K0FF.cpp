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
		
		int arr[5]={0};
		for(int i=0;i<n;i++)
		{
			string str;
			cin>>str;
			if(str=="cakewalk") arr[0]++;
			else if(str=="easy") arr[1]++;
			else if(str=="simple") arr[2]++;
			else if(str=="easy-medium"|| str=="medium") arr[3]++;
			else if(str=="medium-hard"||str=="hard") arr[4]++;
		}
		if(arr[0]>0&&arr[1]>0&&arr[2]>0&&arr[3]>0&&arr[4]>0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}