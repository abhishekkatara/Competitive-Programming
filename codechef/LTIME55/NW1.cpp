#include <bits/stdc++.h>
	 
using namespace std;
	 
typedef long long ll;
	 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
	 
		ll w;
		cin>>w;
		string str;
		cin>>str;

		ll arr[7]={0};

		ll cnt;
		if(str=="sun"){
			cnt=0;
		}
		else if(str=="mon"){
			cnt=1;
		}
		else if(str=="tues"){
			cnt=2;
		}
		else if(str=="wed"){
			cnt=3;
		}
		else if(str=="thurs"){
			cnt=4;
		}
		else if(str=="fri") {
			cnt=5;
		}
		else{
			cnt=6;
		}
		for(int i=0;i<w;i++){
			arr[cnt]++;
			cnt++;
			if(cnt>=7)
				cnt=0;
		}

		for(int i=1;i<7;i++)
			cout<<arr[i]<<" ";
		cout<<arr[0]<<endl;	
	}
	return 0;
}