#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main(){
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
   	cout.tie(NULL);
	lld t;
	cin>>t;

	while(t--){
		lld n;
		double temp = INT_MIN;
		cin>>n;
		lld ar[n];
		for(int i=0;i<n;i++){
			cin>>ar[i];
			if(ar[i]>temp){
			   temp = ar[i];
			}
		}
		lld c,d,s;
		cin>>c>>d>>s;
		double ans=(c-1)*((double)temp);
		printf("%0.9f\n", ans);
	}
} 