#include <bits/stdc++.h>

using namespace std;

#define lld long long int  
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	lld n;
	cin>>n;

	lld ar[n][5];
	
    for(int i=0;i<n;i++){
		int count=0;
		for(int j=0;j<5;j++){
			cin>>ar[i][j];
			if(ar[i][j]==1){
			  count++;
            }
		}

		if(count==0){
		 cout<<"Beginner"<<endl;
        }

		else if(count==1){
		  cout<<"Junior Developer"<<endl;
        }
		
        else if(count==2){
		  cout<<"Middle Developer"<<endl;
        }
		
        else if(count==3){
		  cout<<"Senior Developer"<<endl;
        }
		
        else if(count==4){
		  cout<<"Hacker"<<endl;
        }
		
        else{
		   cout<<"Jeff Dean"<<endl;
        }
	}
}