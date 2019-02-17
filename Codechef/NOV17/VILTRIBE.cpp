#include <bits/stdc++.h>
	 
using namespace std;
	 
#define lld long long int
#define size 100001
int main(){
	 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	 
	int t;
	cin>>t;
	char arr[size];
	int count;
	while(t--){
	 
		int ans[2]={0,0};
		cin>>arr;
		char check;
	 
		if(arr[0]=='A'){
			check='A';
		}
		else if(arr[0]=='B'){
			check='B';
		}
		else{
			check='.';
		}
		lld i=0;
		count=0;
		lld n = strlen(arr);
		
		while(i<n){
	 
			if(arr[i]=='.'){
				count+=1;
			}
			
			else if(arr[i]==check){
				ans[check-'A']+=count+1;
				count=0;
			}
			
			else if(arr[i]!=check){
				
				count=0;
				check=arr[i];
				ans[check-'A']+=1;
			}
			i++;
		}
		cout<<ans[0]<<" "<<ans[1]<<endl;
	}
}