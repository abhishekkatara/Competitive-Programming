#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;

		set<char> set;

		for(auto x:str)
			set.insert(x);

		if(set.size()!=str.length()) cout<<"yes";

		else
		{
			cout<<"no";
		}
		cout<<endl;
	}
	return 0;
}

