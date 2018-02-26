#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	lld t;
	cin>>t;
	while(t--){
		vector<lld> v[26];
		string str;
		cin>>str;
        lld size = str.length();
		lld ar[size+1];
		for(lld i=0;i<size;i++){
            v[str[i]-'a'].push_back(i+1);
		}
		lld cnt=0;
		for(lld i=0;i<26;i++){
            if(v[i].size()%2==1){
          	    cnt++;
            }
		}
		if((cnt!=1 && size%2==1)||(cnt!=0 && size%2==0)){
			cout<<"-1"<<endl;
		}
		else{	
	       lld m=1,n=size;
            if(size%2==0){
                 for(lld i=0;i<26;i++){
                 	for(lld j=0;j<v[i].size();j+=2){
                          ar[m++]=v[i][j];
                          ar[n--]=v[i][j+1];
                 	}
                 }
             }
             else{
            	lld m=1,n=size;
                for(lld i=0;i<26;i++){
               	   if(v[i].size()%2==0){
                          for(lld j=0;j<v[i].size();j+=2){
                          	ar[m++]=v[i][j];
                          	ar[n--]=v[i][j+1];
                          }
                   	   }

                   	   else{
                   	   	    ar[size/2+1]=v[i][0];
                            for(lld k=1;k<v[i].size();k+=2){
                                   ar[m++]=v[i][k];
                                   ar[n--]=v[i][k+1];
                            }
                   	   }
                   }
            }
            lld i=0;
            while(i!=size){
                  cout<<ar[i+1]<<" ";
                  i++;
             }
             cout<<endl;
		}
	}
} 