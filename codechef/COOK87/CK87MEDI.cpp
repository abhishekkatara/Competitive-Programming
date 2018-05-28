#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;++i)cin>>arr[i];
			sort(x,x+n);
		cout<<arr[(n+k)/2]<<"\n";
	}
	return 0;
}