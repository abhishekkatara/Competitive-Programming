#include <bits/stdc++.h>
	 
using namespace std;
	 
#define lld long long int
	 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		lld n,q;
		cin>>n>>q;
		
		lld d[n];
		lld queries[q];
		lld x=1;
		
		for(int j=0;j<n;j++)
		{
			cin>>d[j];
			x*=d[j];
		}
		for(int k=0;k<q;k++)
		{
			cin>>queries[k];
			queries[k] /= x;
			cout<<queries[k]<<" ";
		}
		cout<<endl;
		
	}
	return 0;
	 
}