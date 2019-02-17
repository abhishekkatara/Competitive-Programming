/******************************************
*    AUTHOR:         Abhishek Katara      *
*    INSTITUITION:   IIIT Vadodara        *
******************************************/
 
#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))
#define all(v)    v.begin(),v.end()
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int a,int b){int temp;temp=a;a=b;b=temp;}
ull gcd(ull a,ull b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;
  if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}
ull mult1(ll a,ll b){ll res = 0;a %= MOD; while (b){if (b & 1){res = (res + a) % MOD;}
    a = (2 * a) % MOD;b >>= 1;  }return res;}
#define INF 1000000001
const int base = 27;
int val[300007], HashValR[300007], HashVal[300007];
string str;


void preprocess(){
    
}//end preprocess

ll hashValR(ll l, ll r) {
    if(l > r){
        return 0;
    }
    return ((HashValR[r] - HashValR[l-1]) % MOD + MOD) % MOD * val[str.size()-r] % MOD;
}

ll hashVal(ll l, ll r) {
    if(l > r) {
        return 0;
    }
    return ((HashVal[r] - HashVal[l-1]) % MOD + MOD) % MOD * val[str.size()-r] % MOD;
}
 

void refresh(){
 
}//end refresh

void compute(){
    cin >> str;

    bool flag = false;
    ll size = str.size();
    ll ans = 2;

    val[0] = 1;
    FOR(i, 1, str.size()){
        val[i] = val[i-1] * base % MOD;
    }

    HashVal[0] = 0;

    FOR(i, 1, str.size()){
        HashVal[i] = (HashVal[i-1] + (str[i-1]-'a'+1) * val[i]) % MOD;
    }
    
    reverse(str.begin(), str.end());
    HashValR[0] = 0;
    FOR(i, 1, str.size()){
        HashValR[i] = (HashValR[i-1] + (str[i-1]-'a'+1) * val[i]) % MOD;
    }

    for (ll i=1;i<size/2;i++){
        if(str[i-1] != str[i]){
            flag = true;
        }
    }
    
    if(!flag){
        cout << "Impossible" << endl;
        exit(0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ;
    }

    for(ll i=1;i<size;i++){
        string str1 = str.substr(i, size-i) + str.substr(0, i);
        string s2 = str1;
        reverse(str1.begin(), str1.end());
        if(s2 != str && s2 == str1){
            ans = 1;
        }
    }

    if(ans == 1){
        cout << "1" << endl;
    }
    else{
        cout << "2" << endl;
    }
}//end compute
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("tc_out1.txt", "r", stdin);
    //freopen("tc_out.txt", "w", stdout);
    preprocess();
    
    int t = 1;
    
    //cin>>t;
    while(t--){
        compute();
    }//end while  
   
    //return 0;
}