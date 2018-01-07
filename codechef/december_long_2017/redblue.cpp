#include <bits/stdc++.h>

using namespace std;

#define lld long long int
const int size = 10000;

int N, M, idx;
int aRed[size], coor[size];
struct node{
	int ar[size << 2];
	int ar1[size << 2];

	void update(int q,int l,int r,int L,int R,int v){
		if (L>R) return;

		if(l>=L&&r<=R){
			ar[q] += v;
			ar1[q] += v;
			return;
		}
		int mid = (l+r) >> 1;

		if(ar[q]){
			ar1[q << 1] += ar[q];
			ar1[q << 1|1] += ar[q];
			ar[q << 1] += ar[q];
			ar[q << 1|1] += ar[q];
			ar[q] = 0;
		}

		if(L<=mid){
			update(q << 1,l,mid,L,R,v);
		}
		
		if(mid<R){
			update(q << 1|1,mid+1,r,L,R,v);
		}
		ar1[q] = min(ar1[q << 1],ar1[q << 1|1]);

	}

	void same(int x){
		update(1,1,N,1,x-1,-1);
		update(1,1,N,x,N,1);
	}

	void diff(int x) {
		update(1,1,N,1,x-1,1);
		update(1,1,N,x,N,-1);
	}

	void Clear() {
		memset(ar, 0, sizeof ar);
		memset(ar1, 0, sizeof ar1);
		idx = 0;
	}
} B,R;

struct P{
	int x, y, c;
	P() {}
	P(int x,int y,int c) : x(x), y(y), c(c) {}

	friend bool operator < (const P &a,const P &b){
		if(a.x!=b.x){
			return b.x>a.x;
		}
		return b.y>a.y;
	}
} p[size];

struct E{
	int a,b,n1,n2;

	E() {}
	E(int n1, int n2, int a, int b) : n1(n1), n2(n2), a(a), b(b) {}

	friend bool operator < (const E &a,const E &b){
		if(1LL*a.n1*b.n2!=1LL*b.n1*a.n2){
			return 1LL * a.n1 * b.n2 > 1LL * b.n1 * a.n2;
		}
		if(a.b!=b.b){
			return b.b>a.b;
		}
		return b.a>a.a;
	}
} e[size*size];


void Clear() {
	R.Clear(); B.Clear();
	idx = 0;
}

void Swap(int a,int b){
	int &x = coor[a];
	int &y = coor[b];
	
	if(aRed[x]^aRed[y]){
		if(aRed[x]){
			R.diff(x);
			B.same(x);
			
			R.same(y);
			B.diff(y);
		}
		else{
			R.same(x);
			B.diff(x);
			
			R.diff(y);
			B.same(y);
		}
		swap(aRed[x],aRed[y]);
	}
	swap(x,y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	
	int t;
	cin>>t;

	while(t--){
		Clear();
	int i, j, x, y;
	cin>>N>>M;

	for(i=1;i<=N;i++){
		cin>>x>>y; 
		p[++idx] = P(x,y,0);
	}

	for(i=1;i<= M;i++){
		cin>>x>>y; 
		p[++idx] = P(x,y,1);
	}

	M = 0;
	N = idx;

	for(i=1;i<=N;i++){
		R.update(1,1,N,i,i,i);
		B.update(1,1,N,i,i,i);
	}

	sort(p+1, p+1+N);

	for(i=1;i<=N;i++){
		aRed[i] = p[i].c;
	}
	
	for(i=1;i<=N;i++){
		coor[i] = i;
	}
	
	for(i=1;i<=N;i++){
		if(aRed[i]){
			B.diff(i);
		}
		
		else{
			R.diff(i);
		}
	}

	for(i=1;i<=N;i++){
		for(j=i+1;j<=N;j++){
			e[++M] = E(p[i].y-p[j].y,p[i].x-p[j].x,i,j);
		}
	}

	sort(e+1,e+1+M);
	int ans = N;

	for(i=1;i<=M;i++){
		Swap(e[i].a, e[i].b);
		if(i<M && 1LL*e[i].n1*e[i+1].n2 == 1LL*e[i+1].n1*e[i].n2) continue;
		
		ans = min(ans, R.ar1[1]);
		ans = min(ans, B.ar1[1]);
	}
	cout<<ans<<endl;
	}
	return 0;
}