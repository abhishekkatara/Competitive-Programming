#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	string str;
	getline(cin,str);
	while(t--)
	{
		vector<int> v;
		int len;
		
		getline(cin,str);
		
		stringstream ss(str);
		while(ss>>len)
		{
			v.push_back(len);
		}
		sort(v.begin(),v.end());
		
		if(v[v.size()-1]==v.size()-1)
		{
			cout<<v[v.size()-2]<<"\n";
		}
		else
		{
			cout<<v[v.size()-1]<<"\n";
		}
	}
}