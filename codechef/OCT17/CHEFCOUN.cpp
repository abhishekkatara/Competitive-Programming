#include <iostream>
#include <bits/stdc++.h>
	 
using namespace std;
	 
	//#defineunsignedintlonglong
	 
int wrongSolver(std::vector <unsigned int> a)
{
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		int val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	return where;
}
	 
int main()
{
	int t;
	cin>>t;
	 
	while(t--)
	{
		int n ;
		cin >> n;
	 
		std::vector<unsigned int> v;
		unsigned int a;
		for(int i=0;i<n;i++)
		{
			cin>> a;
	 
			v.push_back(a);
		}
	 
	 
		cout<<wrongSolver(v)<<endl;
	}
	//return 0;
}