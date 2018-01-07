#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,n,m;
	string str[110];
	char carr[110][110];
	char carr1[110][110];
	
	cin>>t;

	while(t--){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}

	char c = 'R';

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0){
				if(j==0){
					carr[i][j] = c;
				}
				else{
					if(carr[i][j-1]=='R'){
						carr[i][j]='G';
					}
					else{
						carr[i][j]='R';
					}
				}
			}
			else{
				if(carr[i-1][j]=='R'){
					carr[i][j] = 'G';
				}
				else{
					carr[i][j] = 'R';
			}	
			}
		}
	}
	c = 'G';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0){
				if(j==0){
					carr1[i][j] = c;
				}
				else{
					if(carr1[i][j-1]=='R'){
						carr1[i][j]='G';
					}
					else{
						carr1[i][j]='R';
					}
				}
			}
			else{
				if(carr1[i-1][j]=='R'){
					carr1[i][j] = 'G';
				}
				
				else{
					carr1[i][j] = 'R';
				}	
			}
		}
	}

	int sum = 0;
	int sum1 = 0;
	int ans = 1000000000;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c1 = carr[i][j];

			if(str[i][j]=='R' && carr1[i][j]=='G'){
				sum1 += 5;
			}

			else if(str[i][j]=='G' && carr1[i][j]=='R'){
				sum1 += 3;
			}
			
			if(str[i][j]=='R' && carr[i][j]=='G'){
				sum += 5;
			}

			else if(str[i][j]=='G' && carr[i][j]=='R'){
				sum += 3;
			}
			
		}
		
	}
	ans = min(sum,sum1);
	cout<<ans<<endl;
	}
	return 0;
}																										