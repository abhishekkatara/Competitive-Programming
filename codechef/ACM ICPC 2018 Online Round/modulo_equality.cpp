#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main()
 {	
 	ios::sync_with_stdio(false);
 	cin.tie(NULL);

	lld t;
	cin>>t;

	while(t--)
	{
		lld n;
		cin>>n;

		lld arr1[n],arr2[n],arr_idx[n];
		
		for(lld i=0;i<n;i++)
		{
			cin>>arr1[i];
		}
 
		for(lld i=0;i<n;i++)
		{
			cin>>arr2[i];
 		}
 
		for(lld i=0;i<n;i++)
		{
			arr_idx[i]=arr1[i]%arr2[i];
 		}
		sort(arr_idx,arr_idx+n);
 
		lld uttar,max=0;

		for(lld j=0;j<n;j++)
		{
			uttar=1;
			while(arr_idx[j]==arr_idx[j+1]&& n>j+1 )
		    {
		    	uttar++;
		    	j++;
		    }
 
		    if(max<uttar)
		    {
		    	max=arr_idx[j];
			}
		}
		uttar=0;
		for(lld i=0;i<n;i++)
		{
				while(arr1[i]%arr2 [i]!=max && i<n)
				{
					uttar++;
					arr1[i]++;
				}
		}
		cout<<uttar<<endl;
	}
}