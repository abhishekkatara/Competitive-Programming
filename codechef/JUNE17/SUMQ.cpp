#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;
int main()
{
	int t,result;
	cin>>t;
	ll m;
	while(t--)
	{
		int p,q,r;
		cin>>p>>q>>r;
		ll result=0;
		vector <ll> X,Y,Z;
	 
		for(int i=0;i<p;i++)
		{
			cin>>m;
			X.push_back(m);
		}

		for(int i=0;i<q;i++)
		{
			cin>>m;
			Y.push_back(m);
		}
		for(int i=0;i<r;i++)
		{
			cin>>m;
			Z.push_back(m);
		}

		sort(X.begin(),X.end());
		sort(Y.begin(),Y.end());
		sort(Z.begin(),Z.end());

		for(int i=0;i<q;i++)
		{
			int temp1 , temp2;
			temp1 = upper_bound(Z.begin(),Z.end(),Y[i])-Z.begin();
			temp2 = upper_bound(X.begin(),X.end(),Y[i])-X.begin();
			if(X[temp2]>Y[i])
			{
				temp2--;
			}

			if(Z[temp1]>Y[i])
			{
				temp1--;
			}

			if(X[p-1]<=Y[i])
			{
				temp2=p-1;
			}
	 
			if(Z[r-1]<=Y[i])
			{
				temp1=r-1;
			}

			for(int j=0;j<=temp2;j++)
			{
				for(int k=0;k<=temp1;k++)
				{
					result = result%MOD;
					result = (result+(((X[j]%MOD + Y[i]%MOD)%MOD)*((Y[i]%MOD + Z[k]%MOD)%MOD)%MOD))%MOD;

				}

			}
		}
		printf("%d\n", result);
	}
	return 0;
}