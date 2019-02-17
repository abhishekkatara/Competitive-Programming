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
		ll n,c,d;
		cin>>n>>c>>d;
		
		ll g =(c+d)%10;
		if(g==0){
			if((c+d)%3==0){
				cout<<"YES"<<endl;
			}
	 
			else{
				cout<<"NO"<<endl;
			}
		}
	 
		else if(g==5){
			if((c+d+5)%3==0){
				cout<<"YES"<<endl;
			}
	 
			else{
				cout<<"NO"<<endl;
			}
		}
	 
		else{
			ll m = (c+d+g)%10;
			ll k = (n-3)/4;
			ll f = (n-3)%4;
			ll sum = k*2;
			
			if(f==1 && m==2){
				sum += 2;
			}
			if(f==1 && m==4){
				sum += 4;
			}
			if(f==1 && m==6){
				sum += 6;
			}
			if(f==1 && m==8){
				sum += 8;
			}
			if(f==2 && m==2){
				sum += 6;
			}
			if(f==2 && m==4){
				sum += 12;
			}
			if(f==2 && m==6){
				sum += 8;
			}
			if(f==2 && m==8){
				sum += 14;
			}
			if(f==3 && m==2){
				sum += 14;
			}
			if(f==3 && m==4){
				sum += 18;
			}
			if(f==3 && m==6){
				sum += 12;
			}
			if(f==3 && m==8){
				sum += 16;
			}
			sum += c+d+g;
			sum %= 3;
			
			if(sum==0){
				cout<<"YES"<<endl;
			}
	 
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
