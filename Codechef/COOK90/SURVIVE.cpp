#include <bits/stdc++.h>
	 
	using namespace std;
	typedef long long ll;
	
	int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	ll t;
	cin>>t;
	 
	while(t--){
	ll n,k,s;
	cin>>n>>k>>s;
	 
	if(n<k){
	cout<<"-1"<<endl;
	}
	 
	else{
	if(s<7){
	ll f = s*k;
	if(f%n==0){
	cout<<f/n<<endl;
	}
	else{
	cout<<f/n+1<<endl;
	}
	}
	 
	else{
	if(k>6*(n-k)){
	cout<<"-1"<<endl;
	}
	 
	else{
	ll f = s*k;
	if(f%n==0){
	cout<<f/n<<endl;
	}
	 
	else{
	cout<<(f/n)+1<<endl;
	}
	}
	}
	}
	}
	}


