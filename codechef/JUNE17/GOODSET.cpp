#include <iostream>
#include <bits/stdc++.h>
	 
using namespace std;
	 
int main()
{
	int t;
	cin>>t;
	vector<int> vec;
	for(int i=1; i<500; i=i+2)
	{
		vec.push_back(i);
	}
	 
	while(t--)
		{ int n;
			cin >> n;
			for(int j=0;j<n;j++)
			{
				cout<<vec[j]<<" ";
			}
			cout<<endl;
		}	 
	return 0;
}