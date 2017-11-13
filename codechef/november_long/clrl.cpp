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
        lld n,r;
        cin>>n>>r;
        lld arr[n];
        lld min1=10000000001;
        lld max1=-1;
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int check1=0,check2=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                continue;
            }
            else{
                check1=1;
            }
        }
 
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                continue;
            }
            else{
                check2=1;
            }
        }
 
        for(int i=0;i<n;i++){
            if(arr[i]>r){
                max1=arr[i];
                 break;
            }
            
            else{
                continue;
            }
    }

    for(int i=0;i<n;i++){
        if(arr[i]<r){
            min1=arr[i];
            break;
        }
    else{
        continue;
    }
    }
    int check=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]>r){
            if(arr[i]<=max1){
                max1=arr[i];
            }
            else{
                check=1;
                break;
            }
    }
        else{
            if(arr[i]>=min1){
                min1=arr[i];
            }
            else{
                check=1;
                break;
            }
        }
 
}

    if(n==1||n==2||check1==0||check2==0){
        cout<<"YES"<<endl;
    }

    else{   
        if(check==1){
            cout<<"NO"<<endl;
        }
    else{
        cout<<"YES"<<endl;
    }
}
}  
} 