#include <bits/stdc++.h>

using namespace std;

#define lld long long int
const lld M = 110010;

lld ar[M*220][2];
lld aR[M],val[M*220];
lld cnt;

void Insert(lld x,lld M,lld y){
	lld idx = aR[x],i,j;
	for(lld i=20;~i;i--){
		j = M & 1;
		if(!ar[idx][j]){
			ar[idx][j] = ++cnt;
		}
		idx = ar[idx][j];
		M >>= 1;
	}
	val[idx] += y;
}
lld queries(lld M,lld x){
	lld idx = aR[x],i,j;
	for(lld i=20;~i;i--){
		j = 1&M;

		if(!ar[idx][j]){
			return 0;
		}
		idx = ar[idx][j];
		M >>= 1;
	}
	return val[idx];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lld n,query;
	cin>>n>>query;
	lld a[M],p[M],a_l[M],a_r[M];

	lld k = (sqrt(n)/ 4+1)*3;
	for(lld i=1;i<=n;i++){ 
		aR[i] = i;
		cnt = n+1;
	}
	for(lld i=1;i<=n;i++){
		cin>>a[i];
	}

	for(lld i=1;i<=n;i++){
		p[i] = p[i-1]^a[i];
	}
	lld tmp[M];

	for(lld i=1;i<=n;i++){
		tmp[i] = (i-1)/k + 1;
		if(!a_l[tmp[i]]){
			a_l[tmp[i]] = i;
		}
		a_r[tmp[i]] = i;
	}
	
	k = tmp[n];

	for(lld i=1;i<=k;i++){
		for(lld j=a_l[i];j<=a_r[i];j++){
			Insert(i, p[j], 1);
		}
	}
	while(query--){
		lld type, x, y;
		lld Xor[M];
		cin>>type>>x>>y;

		if(1&type){
			y  ^= a[x];
			a[x] ^= y;
			
			for(lld i=x;i<=a_r[tmp[x]];i++){
				Insert(tmp[x], p[i], -1);
				p[i] ^= y;
				Insert(tmp[x], p[i], 1);
			}

			for(lld i=tmp[x]+1;i<=k;i++){ 
				Xor[i] ^= y;
			}
		}

		else{
			lld ans = 0;
			for(lld i=1;i<=tmp[x]-1;i++){
				ans += queries(y ^ Xor[i],i);
			}

			for(lld i = a_l[tmp[x]];i<=x;i++){
				if((p[i]^Xor[tmp[x]]) == y){
				 ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 