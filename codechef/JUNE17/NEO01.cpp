#include <iostream>
#include <bits/stdc++.h>
	 
using namespace std;
	 
#define ll long long
typedef vector<ll> IntArray;
	 
int main()
{
	int t;
	cin >> t;
	
	 
	while(t--)
	{
		ll n;
		cin>>n;

		if(n==1)
		{
			ll v;
			cin>>v;
		}
	 
		ll sum = 0;
		vector<ll> A(N);
		IntArray::iterator it = A.begin();
		while (n--)
		{
			ll v;
			cin>>v;
			*it++ = v;
			sum += v;
		}
	 
		std::sort(A.begin(), A.end());
	 
		ll result = -10000000000000,p=0,count=0;
	 
		IntArray::const_reverse_iterator rit;
		for (rit=A.rbegin(); rit != A.rend(); rit++)
		{
			const ll &v = *rit;
			sum -= v;
			p += v;
			count++;
	 
			ll calc = p * count + sum;
	 
			if(calc>result)
			{
				result = calc;
			} else {
				break;
			}
		}
		cout <<result<< endl;
	} 
	return 0;
}