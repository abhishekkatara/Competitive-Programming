#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int sie(int a,int b)
{
	int c;
	while(b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	int tmp,a,b;
	cin>>tmp;
	for(int i=0;i <tmp; i++)
	{
		cin>>a>>b;
		cout<<sie(a,b) - 1 <<endl;
	}
	return 0;
}

