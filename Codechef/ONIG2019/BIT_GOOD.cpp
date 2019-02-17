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
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))
#define all(v)  v.begin(),v.end()
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int a,int b){int temp;temp=a;a=b;b=temp;}
ull gcd(ull a,ull b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;
  if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}
ull mult1(ll a,ll b){ll res = 0;a %= MOD; while (b){if (b & 1){res = (res + a) % MOD;}
  a = (2 * a) % MOD;b >>= 1;  }return res;}
#define INF 1000000001 
void preprocess(){
 
}//end preprocess
 
void refresh(){
 
}//end refresh

void compute(){
    ll n, x, ans = 0;
    cin >> n;

    vector<ll > A;
    set<ll> s;

    REP(i, n){
        cin >> x;
        A.push_back(x);
    }
    
    sort(A.begin(), A.end());

    REP(i, n){
        if(A[i] < 0){
            s.insert(A[i]);
        }
    }
    
    ll temp[n+10] = {0};
    
    FORR(i, n-1){
        temp[i] = temp[i+1];
        if(s.find(-A[i]) != s.end()){
            temp[i]++;
        }
    }
    
    vector<ll>::iterator up;
    FORR(i, n-4){
        up = upper_bound (A.begin(), A.end(), A[i]);
        ll it = up - A.begin();
        if((n - (temp[it] + it)) >= 3){
            if(A[i] > 0){
                ans = (ans + A[i]) % MOD;
            }
        }
    }
    cout << ans << endl; 
}//end compute
 
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    //freopen("tc_out1.txt", "r", stdin);
    //freopen("tc_out.txt", "w", stdout);
    int t = 1;
    preprocess();
    
    //cin>>t;
    while(t--){
        compute();
    }//end while  
   
    //return 0;
}