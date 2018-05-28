#include <iostream>
#include <bits/stdc++.h>
	 
using namespace std;
	 
int main()
{
	int t,n,k,s;
	
	cin>>t;
	
	while(t--)
	{
		vector<int> v;
		cin>>n>>k;
		int i,temp=0;
		
		for(i=0;i<n;i++)
		{
			cin>>s;
			v.push_back(s);
		}
		
		sort(v.begin(),v.end());
		
		int cnt=0;
		i=0;
		int ans;
		for(i=0;i<n;)
		{
			if(v[i]==cnt)
			{
				i++;
				cnt++;
				continue;
			}
			else
			{
				temp++;
				if(temp<=k) { cnt++; }
				else { ans = cnt; break; }
			}
		}
		if(i==n)
			ans=cnt - temp + k;
		cout<<ans<<endl;
	}
	return 0;
}