#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n=0,c=1,even=0,odd=0,i=0,count=0;
    cin>>n;
    ll *a=new ll[n];

    for(i=0;i<n;++i){
    cin>>a[i];

    if(a[i]%2==0){
        ++even;
    }

    else{
        ++odd;
    }
    
    }
    while(1){
        if(even==0 && odd==0){
            break;
        }

        else if(c%2==0 && even==0){
            ++count;
        }

        else if(c%2!=0 && odd==0){
            ++count;
        }

        else if(c%2==0 && even>0){
            --even;
        }

        else if(c%2!=0 && odd>0){
            --odd;
        }
        else{
            ++c;
        }
    }   
    cout<<count<<endl;
}