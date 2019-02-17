#include <bits/stdc++.h>
using namespace std;
#define lld long long int
	 
int main() {
	lld t;
	cin>>t;
	while(t--){
		lld n;
		cin>>n;
		lld temp = sqrt(8*n + 1) - 1;
		temp /= 2;
		cout<<min(temp + n - ((temp)*(temp+1))/2,temp + 1 + ((temp+1)*(temp+2))/2 - n)<<endl;
	}
}