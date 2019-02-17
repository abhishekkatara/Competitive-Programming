#include <bits/stdc++.h>
	 
using namespace std;
	 
typedef long long ll;
	 
ll sol(ll a ,ll n ){
	ll final =1;
	ll tmp=1;
	a %= 9;
	while(n!=1)
	{
		if(n%2==0)
		{
			a *= a;
			n /= 2;
		}
		else
		{
			tmp *= a;
			a *= a;
			n /=2;
		}
		a %= 9;
		tmp %= 9;
	}
	final = a*tmp;
	final = (final%9+8)%9 + 1;
	return final;
	 
}
	 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll a,n;
		cin>>a>>n;
		
		cout<<sol(a,n)<<endl;
	}
}