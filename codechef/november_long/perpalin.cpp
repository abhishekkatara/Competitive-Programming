#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main(){   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        
        int n,p;
        cin>>n>>p;
 
        char str[n];
 
        if(p==1||p==2){
            cout<<"impossible"<<endl;
        }
        
        else{
                str[0]=str[p-1]='a';
                for(int i=1;i<p-1;i++){
                    str[i]='b';
                }

                int temp = n/p;
                
                for(int j=0;j<temp;j++){
                    for(int i=0;i<p;i++){
                        cout<<str[i];
                    }
                }
                cout<<"\n";
        }
    }
}