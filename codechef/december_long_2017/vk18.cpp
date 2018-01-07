#include <bits/stdc++.h>

using namespace std;

#define ll long long int

const int size = 2000010;
const int k = 2000000;

ll arr[size], arr1[size], arr2[size], temp[size];

int Calc(int x){
	int arr[2] = {0, 0};
	while (x){
		arr[x % 2] += x % 10;
		x /= 10;;
	}
	return abs(arr[0] - arr[1]);
}
void init(int n){

	for (int i=1;i<n;i++){ 
		arr[i] = Calc(i);
	}

	for (int i=1;i<n;i++){ 
		arr1[i] = arr1[i-1] + (i-1)*arr[i];
	}

	for (int i=n;i;i--){
	 arr2[i] = arr2[i+1] + (n-i+1)*arr[i];
	}

	for (int i=n;i;i--){ 
		temp[i] = temp[i+1] + arr[i];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	int t;
	cin>>t; 
	init(k);

	while(t--){
		ll n;
		cin>>n;
		int m = 2*n + 1;
		ll ans = arr1[n+1];
		ll diff = arr2[n+2] - arr2[m];
		ll x = 2000001 - m;
		diff -= x*(temp[n+2] - temp[m]);
		ans += diff;
		cout<<ans<<endl;

	}
	return 0;
}