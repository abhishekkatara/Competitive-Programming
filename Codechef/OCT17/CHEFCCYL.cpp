#include <iostream>
#include <bits/stdc++.h>
	 
	using namespace std;
	 
	const int M = 1e5 + 5;
	 
	int dist[M][3];
	int In[M];
	int Out[M];
	
	struct Cycle
	{
	int V0, V1;
	int size;
	vector<int> dist1;
	vector<int> sum_dist1;
	
	void init()
	{
	sum_dist1.resize(size);
	sum_dist1[0] = dist1[0];
	for(int i = 1; i < size; ++i)
	{
	sum_dist1[i] = sum_dist1[i-1] + dist1[i];
	}
	}
	
	int get_dist(int u, int v)
	{
	if(u == v) {return 0;}
	if(u > v) {swap(u, v);}
	 
	int tmp = sum_dist1[v-1] - (u == 0 ? 0 : sum_dist1[u-1]);
	
	return min(tmp, sum_dist1[size-1] - tmp);
	}
	
	int in_paht()
	{
	return get_dist(V1, V0);
	}
	};
	
	Cycle cyc[M];
	int s;
	int incyc_dist(int c, int u, int v)
	{
	return cyc[c].get_dist(u, v);
	}
	
	int cyc_dist(int c1, int c2, int t)
	{
	if(c1 > c2){ swap(c1, c2); }
	if(t == 0)
	{
	return In[c2-1] - (c1 == 0 ? 0 : In[c1-1]) + Out[c2-1] - Out[c1];
	}
	else
	{
	return s - cyc[c1].in_paht() - cyc[c2].in_paht() - (In[c2-1] - (c1 == 0 ? 0 : In[c1-1]) + Out[c2-1] - Out[c1]);
	}
	return 0;
	}
	
	int main()
	{
	int t;
	cin>>t;
	 
	while(t--)
	{
	int n, q;
	cin>>n>>q;
	 
	int a;
	for(int i=0;i<n;i++)
	{
	cin>>a;
	 
	cyc[i].dist1.resize(a);
	cyc[i].size = a;
	 
	for(int j=0;j<a;j++)
	cin >> cyc[i].dist1[j];
	cyc[i].init();
	}
	s = 0;
	for(int i=0;i<n;i++)
	{
	int v0, v1;
	cin >> dist[i][0]>>dist[i][1]>>dist[i][2];
	dist[i][0]--;
	dist[i][1]--;
	}
	for(int i=0;i<n;i++)
	{
	if(i == 0)
	{
	cyc[i].V0 = dist[n-1][1];
	cyc[i].V1 = dist[i][0];
	}
	
	else
	{
	cyc[i].V0 = dist[i-1][1];
	cyc[i].V1 = dist[i][0];
	}
	s += cyc[i].in_paht() + dist[i][2];
	}
	 
	Out[0] = cyc[0].in_paht();
	In[0] = dist[0][2];
	 
	for(int i=1;i<n;i++)
	{
	In[i] = In[i-1] + dist[i][2];
	Out[i] = Out[i-1] + cyc[i].in_paht();
	}
	
	for(int i=0;i<q;i++)
	{
	int v1, c1, v2, c2;
	cin >>v1>>c1>>v2>>c2;
	c1--;
	c2--;
	v1--;
	v2--;
	
	if(c1>c2)
	{
	swap(c1,c2);
	swap(v1,v2);
	}
	cout << min(incyc_dist(c1, v1, cyc[c1].V1)
	+ cyc_dist(c1, c2, 0)
	+ incyc_dist(c2, v2, cyc[c2].V0),
	incyc_dist(c1, v1, cyc[c1].V0)
	+ cyc_dist(c1, c2, 1)
	+ incyc_dist(c2, v2, cyc[c2].V1))<<endl;
	}
	}
	return 0;
	}