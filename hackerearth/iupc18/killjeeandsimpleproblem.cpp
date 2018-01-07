#include <bits/stdc++.h>

using namespace std ;

typedef long long ll; 
ll Fact[50],arr[50];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Fact[0] =1ll ;
    for(int i=1;i<=20;i++){
        Fact[i] = Fact[i-1]*i;
    }

    ll n;
    cin>>n;
    int idx; 
    for(int i=1;i<=20;i++){
        if(Fact[i]>=n){
            idx = i;
            break;
        }
    }

    ll final =0 ; 
    for( int i=97;i<=97+idx-1;i++){
        final += i;
    }
    cout<<final<<endl;
}