#include <bits/stdc++.h>

using namespace std;
	 
typedef long long ll;
	 
ll maxFind(vector<ll> v,ll n,ll x){
	ll i = n-1;
	while((i!=-1)&&(v[i]>=x)){
		i--;
	}
	
	if(i==-1){
		return -1;
	}
	 
	else{
		return v[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
	 
		vector<ll> v[n];
	 
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				ll a;
				cin>>a;
				v[i].push_back(a);
			}
			sort(v[i].begin(),v[i].end());
		}
		ll final = v[n-1][n-1];
		ll max = v[n-1][n-1];
		int flag=0;
		
		for(ll i=n-2;i>=0;i--){
			
			ll max2 = maxFind(v[i],n,max);
			if(max2==-1){
				flag=1;
				break;
			}
			else{
				final += max2;
				max = max2;
			}
		}
		
		if(flag==0){
			cout<<final<<endl;
		}
	 
		else{
			cout<<-1<<endl;
		}
		
	}
	
}