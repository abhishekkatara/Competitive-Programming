#include <bits/stdc++.h>
	 
using namespace std;
	 
typedef long long int lld;
	 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	int t;
	cin>>t;
	lld arr[10001];
	while(t--)
	{
		lld n,u,d,i;
		cin>>n>>u>>d;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		int f=1;
	 
		for(i=0;i<n;i++){
			if(arr[i]==arr[i+1]){
				continue;
			}
			else if(arr[i+1]<arr[i]){
				if(d>=arr[i]-arr[i+1]){
					continue;
				}
	 
				else if(f==1){
					f=0;
					continue;
				}
	 
				else{
					break;
				}
			}
	 
			else if(arr[i+1]>arr[i]){
				if(u>=arr[i+1]-arr[i]){
					continue;
				}
	 
				else{
					break;
				}
			}
		}
		if(i<n){
			cout<<i+1<<endl;
		}
		else {
			cout<<i<<endl;
		}
	}
}