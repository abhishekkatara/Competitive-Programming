#include <bits/stdc++.h>

using namespace std;

#define lld long long int 
typedef pair<int, int> mp ;

int cnt,mx;
int  a[1000010],b[1000010];
int ver[1000010],pos[1000010];
int visited[100],arrayre[100],arrayrerere[100];
vector<int> G[1000010];
mp a1[1000010],a2[1000010][2];

void dfs(int x){
	if (x == cnt+1){
		int tmp = 0;
		for (int i=1;i<=cnt;i++){
			if(ver[i]!=ver[arrayre[i]]){
				tmp++;
			}
		}
		if(tmp>=mx){
			mx = tmp;
			for (int i=1;i<=cnt;i++){
				arrayrerere[i] = arrayre[i];
			}
		}
		return ;
	}
	for (int i = 1; i <= cnt; i++)
		if (!visited[i]) {
			visited[i] = 1;
			arrayre[x] = i;
			dfs(x + 1);
			visited[i] = 0;
		}
}
int m;
int main(){
	int t;
	cin>>t;
	while(t--){
	for(int i=1;i<=m;i++){
		G[i].clear();
	}
	mx = 0;
	m = 0;
	cnt = 0;
 	 
 	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		G[a[i]].push_back(i);
		m = max(m, a[i]);
	}
	int n1 = 0;
	int n2 = 0;

	for (int i=1;i<=m;i++){
		if (G[i].size()==1){
			n1++;
			a1[n1] = mp(i,G[i][0]);
		}
		if (G[i].size()==2){
			n2++;
			a2[n2][0] = mp(i,G[i][0]);
			a2[n2][1] = mp(i,G[i][1]);
		}
	}
	int p1 = min(3,n1);
	int p2 = min(2,n2);
	if(n1-p1 ==1){
		p1--;
	}

	if(n2-p2 == 1){
		p2++;
	}
	
	for(int i=1,j=n1;i<=p1;i++,j--){
		++cnt, ver[cnt] = a1[j].first, pos[cnt] = a1[j].second;
	}

	for(int i=1, j=n2;i<=p2;i++,j--){
		++cnt, ver[cnt] = a2[j][0].first, pos[cnt] = a2[j][0].second;
		++cnt, ver[cnt] = a2[j][1].first, pos[cnt] = a2[j][1].second;
	}
 
	n2 -= p2;
	n1 -= p1;
	for (int i=1;i<=n1;i++){
		int j = i+1;
		if (i==n1){
			j = 1;
		}

		b[a1[j].second] = a1[i].first;
	}
	for(int i=1;i<=n2;i++){
		int j =i+1;
		
		if(i==n2){
			j = 1;
		}

		b[a2[j][0].second] = a2[i][0].first;
		b[a2[j][1].second] = a2[i][1].first;
	}
	
	dfs(1);

	for(int i=1;i<=cnt;i++){
		b[pos[i]] = ver[arrayrerere[i]];
	}

	if(n == 1){
		cout<<"0"<<endl;
	}

	else{
		cout<<n1 + n2 * 2 +mx <<endl;
	}

	for(int i=1;i<=n;i++){
		if(i==n){
			cout<<b[i]<<endl;
		}
		else{
			cout<<b[i]<<" ";
		}
	  }
	}
	return 0;
}