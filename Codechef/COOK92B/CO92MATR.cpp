#include <bits/stdc++.h>
using namespace std;
#define lld long long int
	 
bool check(lld i, lld j, lld n, lld m){
	if(i>n||j>m||i<0||j<0){
		return false;
	}
	else return true;
}
	 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	lld t;
	cin >>t;
	while(t--){
		lld n, m;
		cin>>n>>m;
		
		lld a[n][m];
		for(lld i=0;i<n;i++){
			for(lld j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		
		bool flag1 = false;
		
		for(lld i=0;i<n;i++){
			for(lld j=0;j<m;j++){
				bool flag = false;
				if(a[i][j] == -1){
					if(check(i, j-1, n, m)){
						if(check(i-1, j, n, m)){
							a[i][j] = max(a[i-1][j], a[i][j-1]);
						}
						else if(a[i][j-1] > 0) {
							a[i][j] = a[i][j-1];
						}
						else {
							a[i][j] = 1;
						}
					}
					
					else if(!check(i-1, j, n, m)){
						a[i][j] = 1;
					}
					
					else if(a[i-1][j] > 0){
						a[i][j] = a[i-1][j];
					}
					
					else{
						a[i][j] = 1;
					}
				}
				
				if(check(i, j-1, n, m)){
					if(a[i][j] < a[i][j-1])
						flag = true;
				}
				
				if(check(i-1, j, n, m)){
					if(a[i][j] < a[i-1][j])
						flag = true;
				}
				if(a[i][j] > 2000000000 || a[i][j] < 1 ){
					flag = true;
				}
				
				if(flag == true){
					flag1 = true;
					break;
				}
			}
			
			if(flag1 == true){
				break;
			}
		}
		if(flag1 == true){
			cout<<-1<<endl;
			continue;
		}
	 
		else{
			for(lld i=0;i<n;i++){
				for(lld j=0;j<m;j++){
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
		}
	}
}
