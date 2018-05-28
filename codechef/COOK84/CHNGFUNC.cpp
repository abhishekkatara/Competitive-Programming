#include <bits/stdc++.h>
	using namespace std;
	
	int main()
	{
	long long int a,b,count=0LL,res;
	double temp;
	cin>>a>>b;
	for(int x=1;x<=a;x++)
	{
	for(int y=1;y<=b;y++)
	{
	res=sqrt(x*x+y);
	temp=sqrt(x*x+y);
	if(temp>res)
	continue;
	count++;
	
	}
	}
	cout<<count;
	return 0;
	}