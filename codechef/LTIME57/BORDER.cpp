#include <bits/stdc++.h>
	 
using namespace std;
	 
typedef long long int lld;
	 
lld sol(string s,lld n,lld temp_s);
	 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	lld t;
	cin>>t;
	while(t--){
		lld n,q;
		string str;
		cin>>n>>q;
		cin>>str;
		
		while(q--){
			lld p,k;
			cin>>p>>k;
			cout<<sol(str,p,k)<<endl;
		}
	}
}
	 
lld sol(string s,lld n,lld temp_s){
	lld flag,count=0;
	for(int i=0;i<n;i++){
		flag=1;
		for(int j=0;j<=i;j++){
			if(s[n-1-i+j]!=s[j]){
				flag=0;
				break;
			}
		}
	 
		if(flag==1){
			count++;
		}
	 
		if(temp_s==count){
			return i+1;
		}
	 
		
	}
	return -1;
}