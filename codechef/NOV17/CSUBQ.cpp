#include <bits/stdc++.h>
	 
using namespace std;

#define lld long long int
const int N = 5e5+10;
int n, L, R;
	 
struct node{
	lld v;
	int n, arr[4], fl;
	node(){
		fl=1;
	}
	
	lld value(){
		return (fl ? 0:v);
	}
	 
	void set(int x){
		v=0;
		n=1;
		fl=0;
		
		if(x<L){
			arr[0]=arr[1]=arr[2]=arr[3]=1;
		}
	 
		else if(x>R){
			arr[0]=arr[1]=arr[2]=arr[3]=0;
		}
		
		else{
			arr[0]=arr[3]=0, v=arr[1]=arr[2]=1;
		}
	}
	 
	void merge(node l,node r)
	{
		fl=0;
		if(l.fl and r.fl){
			fl=1;
		}
		
		else if(l.fl){
			*this=r;
		}
		
		else if(r.fl){
			*this=l;
		}
		
		else{
			n = l.n + r.n;
			lld arX = l.arr[2] - l.arr[3];
			lld blY = r.arr[1] - r.arr[0];
			v = l.v + r.v + arX*r.arr[0] + arX*blY + l.arr[3]*blY;
			arr[0] = l.arr[0] + (l.arr[0]==l.n ? r.arr[0]:0);
			arr[1] = l.arr[1] + (l.arr[1]==l.n ? r.arr[1]:0);
			arr[2] = r.arr[2] + (r.arr[2]==r.n ? l.arr[2]:0);
			arr[3] = r.arr[3] + (r.arr[3]==r.n ? l.arr[3]:0);
		}
	}
} t[N<<1];

void build(){
	for(int i=n;i--;){
		t[n+i].set(0);
	}
	
	for(int i=n;--i;){
		t[i].merge(t[i<<1], t[i<<1|1]);
	}
}
	 
void update(int p,int v){
	t[n+p].set(v);
	for(int i=n+p;i>>=1;){
		t[i].merge(t[i<<1], t[i<<1|1]);
	}
}
node get(int l,int r){
	node lt, rt;
	 
	for(l+=n,r+=n+1; l<r; l>>=1,r>>=1){
		if(l&1) lt.merge(lt, t[l++]);
		if(r&1) rt.merge(t[--r], rt);
	}
	
	lt.merge(lt,rt);
	return lt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int q,t,x,y,ans;
	cin>>n>>q>>L>>R;
	 
	build();
	 
	while(q--){
		cin>>t>>x>>y;
	 
		if(t==1){
			update(x-1,y);
		}
		
		else{
			ans = get(x-1,y-1).value();
			cout<<ans<<endl;
		}
	}
}