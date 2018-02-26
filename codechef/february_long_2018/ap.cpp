#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x=1;
        ll temp = 0;
        cin>>n;
        n--;
        while(n!=0){
            temp += (n%6)*x;
            x*=10;
            n/=6;
        }
        cout<<temp<<endl;
    }
    return 0;
}