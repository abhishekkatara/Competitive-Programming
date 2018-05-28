#include <bits/stdc++.h>
	 
using namespace std;
	 
typedef long long ll;
	 
ll arr[1000000],n,k,sum,s;
	 
bool check(ll temp_n,ll idx)
{
	if(s==sum/2){
		return true;
		
		return check(n,temp_n-1);
	}
	for(int i=idx;i>=1;i--){
		if(i==k||arr[i]==1)
			continue;
		
		if(sum>=2*(s+i)){
			arr[i] = 1;
			s += i;
			
			bool next = check(n,i-1);
			arr[i] = 0;
			s -= i;
			
			if(next){
				arr[i]=1;
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	 
	while(t--){
		s=0;
		ll b=0;
		cin>>k>>n;
	 
		sum = (n*(n+1))/2-k;
	 
		if(n<4||sum%2!=0){
			cout<<"impossible"<<endl;
		}
	 
		else{
			b = check(n,n);
			
			if(b){
				arr[k]=2;
				
				for(int i=1;i<=n;i++){
					cout<<arr[i];
					arr[i]=0;
				}
				cout<<"\n";
			}
			
			else{
				cout<<"impossible"<<endl;
			}
		}
	}
	return 0;
}