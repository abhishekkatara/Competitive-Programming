#include <bits/stdc++.h>
	 
using namespace std;
	 
typedef long long ll;
	 
ll max(ll a,ll b){
	if(a>b){
		return a;
	}
	 
	else{
		return b;
	}
}

ll maxSubArraySum(vector<int> v, ll n)
{
	ll m_end = 0;
	ll m_start = -10e8;
	
	for (ll i=0;i<n;i++)
	{
		m_end = m_end + v[i];
		if (m_start<m_end)
			m_start = m_end;
		
		if (m_end < 0)
			m_end = 0;
	}
	return m_start;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll s_max;
		
		vector<int> v;
		ll a_sum = 0;
	 
		for(ll i=0;i<n;i++){
			ll a;
			cin>>a;
			v.push_back(a);
			a_sum += a;
			
		}
	 
		ll f1 = maxSubArraySum(v,v.size());
	 
		v.insert(v.end(),v.begin(),v.end());
		
		ll f2 = maxSubArraySum(v,v.size());
		
		if(k==1){
			cout<<f1<<endl;
		}
	 
		else{
			cout<<max(f2,f2+a_sum*(k-2))<<endl;
		}
		
	}
}