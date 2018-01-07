#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
 
ll MOD  = 1000000007;
#define N 1000003
ll Fact[N];
 
void giveChocolate(int idx,int limit,int& count){
     if(idx>limit){ 
       return;
     }

     if(limit==1){
         count++;
         return;
     }
     giveChocolate(1,limit-1,count);
     giveChocolate(idx+1,limit,count);
}
 

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Fact[0] = Fact[1] = 1;
 
   for(ll i=2;i<N;i++){ 
     Fact[i] = (i * Fact[i-1]) % MOD;
   }

   int t;
   cin>>t;
  
   while(t--){
     int n,m;
     cin>>m>>n;
     ll p = m-n+1;
     ll final = (p*Fact[m-1])%MOD;
     cout<<final<<endl;
   }
}
 
