#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define N  4294967291

int main()
{
int t;
cin>>t;

while(t--)
{
	int n;
	cin>>n;
	
	int flag=0;
	unsigned int mn;
	
	if(N%(n-2)==0) { mn=(N/(n-2)); }
    else { mn=(N/(n-3)); flag=1; }

	for(int i=0;i<n-3;i++)
	{
        cout<<mn<<" ";
	}

	if(!flag) { cout<<mn<<" "; }
    else { cout<<(N-(mn*(n-3)))<<" "; }

    cout<<2<<" ";
    cout<<1<<endl;
}
return 0;
}