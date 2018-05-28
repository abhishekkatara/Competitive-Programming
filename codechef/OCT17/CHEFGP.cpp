#include <iostream>
#include <bits/stdc++.h>
	 
using namespace std;
	 
#define lld long long int

int main()
{
	lld t;
	cin>>t;
	 
	while(t--)
	{
		string str;
		cin>>str;
	 
		lld x,y;
		cin>>x>>y;
		lld a,b,m=0,n=0,p,q;
	 
		for(lld j=0;j<str.size();j++)
		{
			if(str[j]=='a')
				m++;
			if(str[j]=='b')
				n++;
		}
	 
		p=a=(lld)(m/x);
		q=b=(lld)(n/y);
		
		
		if(m-(p*x)!=0&&n-(q*y)!=0)
		{
			
			if(p>q)
			{
				for(lld j=0;j<p;j++)
				{
					
					for(lld k=0;k<x;k++)
					{
						cout<<'a';
					}
					
					if(q>0)
					{
						for(lld k=0;k<y;k++)
						{
							cout<<'b';
							q--;
						}
					}
					
					else if(q==0)
					{
						for(lld k=0;k<n-(b*y);k++)
						{
							cout<<'b';
							q--;
						}
					}
	 
					else
						cout<<"*";
				}
	 
				for(lld k=0;k<m-((a)*x);k++)
				{
					cout<<'a';
				}
			}
	 
			if(q>p)
			{
				for(lld j=0;j<q;j++)
				{
					for(lld k=0;k<y;k++)
					{
						cout<<b;
					}
					
					if(p>=1)
					{
						for(lld k=0;k<x;k++)
						{
							cout<<'a';p--;
						}
					}
	 
					else if(p==0)
					{
						for(lld k=0;k<m-(a*x);k++)
						{
							cout<<'a';
							p--;
						}
					}
					else
						cout<<"*";
				}
				for(lld k=0;k<n-(b*y);k++)
					cout<<'b';
			}
			if(q==p)
			{
				for(lld j=0;j<q;j++)
				{
					for(lld k=0;k<x;k++)
					{
						cout<<'a';
					}
					
					for(lld k=0;k<y;k++)
					{
						cout<<'b';
					}
				}
				for(lld k=0;k<m-(a*x);k++)
				{
					cout<<'a';
				}
	 
				for(lld k=0;k<n-(b*y);k++)
				{
					cout<<'b';
				}
			}
			cout<<endl;
			continue;
		}
		if(m-(p*x)==0&&n-(q*y)==0)
		{
			
			if(p>q)
			{
				for(lld j=0;j<p-1;j++)
				{
					
					for(lld k=0;k<x;k++)
					{
						cout<<'a';
					}
					
					if(q>0)
					{
						for(lld k=0;k<y;k++)
						{
							cout<<'b';
							q--;
						}
					}
					else
					{
						cout<<"*";
					}
				}
				for(lld k=0;k<x;k++)
				{
					cout<<'a';
				}
			}
	 
			if(q>p)
			{
				for(lld j=0;j<q-1;j++)
				{
					for(lld k=0;k<y;k++)
					{
						cout<<'b';
					}
					if(p>=1)
					{
						for(lld k=0;k<x;k++)
						{
							cout<<'a';
							p--;
						}
					}
					else
					{
						cout<<"*";
					}
				}
				for(lld k=0;k<y;k++)
				{
					cout<<'b';
				}
			}
			if(q==p)
			{
				for(lld j=0;j<q;j++)
				{
					for(lld k=0;k<x;k++)
					{
						cout<<'a';
					}
	 
					for(lld k=0;k<y;k++)
					{
						cout<<'b';
					}
				}
				
			}
			cout<<endl;
			continue;
		}
		if((n-(q*y))!=0&&(m-(p*x))==0)
		{
			
			q++;
			if(p>q)
			{
				for(lld j=0;j<p-1;j++)
				{
					
					for(lld k=0;k<x;k++)
					{
						cout<<'a';
					}
	 
					if(q>1)
					{
						for(lld k=0;k<y;k++)
						{
							cout<<'b';
							q--;
						}
					}
	 
					else if(q==1)
					{
						for(lld k=0;k<n-(b*y);k++)
						{
							cout<<'b';
							q--;
						}
					}
					else
					{
						cout<<"*";
					}
				}
				for(lld k=0;k<x;k++)
				{
					cout<<'a';
				}
			}
			if(q>p)
			{
				for(lld j=0;j<q-1;j++)
				{
					for(lld k=0;k<y;k++)
					{
						cout<<'b';
					}
	 
					if(p>0)
					{
						for(lld k=0;k<x;k++)
						{
							cout<<'a';
							p--;
						}
					}
					else
					{
						cout<<"*";
					}
				}
				for(lld k=0;k<n-(b*y);k++)
				{
					cout<<'b';
				}
			}
			if(q==p)
			{
				for(lld j=0;j<q-1;j++)
				{
					for(lld k=0;k<x;k++)
					{
						cout<<'a';
					}
					
					for(lld k=0;k<y;k++)
					{
						cout<<'b';
					}
				}
				for(lld k=0;k<x;k++)
				{
					cout<<'a';
				}
				for(lld k=0;k<n-(b*y);k++)
					cout<<'b';
			}
			cout<<endl;
			continue;
		}
		if(m-(p*x)!=0&&n-(q*y)==0)
		{
			p++;
			if(p>q)
			{
				for(lld j=0;j<p-1;j++)
				{
					
					for(lld k=0;k<x;k++)
						cout<<'a';
					if(q>0)
						{for(lld k=0;k<y;k++)
							cout<<'b';q--;}
							else
								cout<<"*";
						}
						for(lld k=0;k<m-(a*x);k++)
							cout<<'a';
					}
					if(q>p)
					{
						for(lld j=0;j<q-1;j++)
						{
							for(lld k=0;k<y;k++)
								cout<<'b';
							if(p>1)
								{for(lld k=0;k<x;k++)
									cout<<'a';p--;}
									else if(p==1)
									{
										for(lld k=0;k<m-(a*x);k++)
											cout<<'a';
									}
									else
										cout<<"*";
								}
								for(lld k=0;k<y;k++)
									cout<<'b';
							}
							if(q==p)
							{
								for(lld j=0;j<q-1;j++)
								{
									for(lld k=0;k<x;k++)
										cout<<'a';
									for(lld k=0;k<y;k++)
										cout<<'b';
								}
								for(lld k=0;k<m-(a*x);k++)
									cout<<'a';
								for(lld k=0;k<y;k++)
									cout<<'b';
							}
							cout<<endl;
							continue;
						}
					}
				}