        #include <bits/stdc++.h>
         
        using namespace std;
         
        typedef unsigned long long ull;
         
        ull min(long arr[][4], long t, long n)
        {
        	ull arr[n];
        	long abc = (sizeof(arr)/sizeof(arr[0]));
         
        	for (long i = 0; i < n; i++)
        	{
        		arr[i] = (arr[i][0])+(arr[i][1]*t)+(arr[i][2]*t*t)+(arr[i][3]*t*t*t);
        	}
        	sort(arr, arr + abc);
         
        	return arr[0];
        }
         
        int main()
        {
         
        	int t; 
        	cin>>t;   
            while(t--)
            {
        		long n, q;
        		cin>>n;
        		long arr[n][4];
        		for(long i = 0; i < n; i++)
        		{
			 cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
        		}
         
        		cin>>q;
        		long t[q];
        		for (long i = 0; i < q; i++)
        			cin>>t[i];
         
        		ull ans[n];
         
        		for(long i=0;i<q;i++){
        				ans[i] = min(arr, t[i], n);
        		}
        		for (long i = 0; i < q; i++)
        			cout<< ans[i]<<endl;
        	}
            return 0;
        } 