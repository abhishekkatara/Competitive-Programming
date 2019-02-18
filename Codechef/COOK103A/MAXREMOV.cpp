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
#define all(v)	v.begin(),v.end()
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
	ll n, k, l, r, mx = 0, x = 0;
	cin >> n >> k;

	ll arr[100005] = {0}, arrl[100005], arrr[100005];
	ll dp[n+1][2]={0};

	memset(arrl, 0, sizeof(arrl));
	memset(arrr, 0, sizeof(arrr));

	FOR(i, 1, n){
		cin >> l >> r;
		
		dp[i][0] = l;
		dp[i][1] = r;

		arrl[l]++;
		arrr[r]++;
		mx = max(mx, r);
	}

	ll req[mx+1] = {0}, ext[mx+1] = {0};

	REP(i, 100005){
		x += arrl[i];
		x -= arrr[i-1];
		arr[i] += x;
	}
	
	FOR(i, 1, mx){
		if(arr[i] == k+1){
			ext[i] = ext[i-1] + 1;
		}
		else{
			ext[i] = ext[i-1];
		}

		if(arr[i] == k){
			req[i] =req[i-1] + 1;
		}
		else{
			req[i] = req[i-1];
		}
	}
	ll ans = -1000000;

	FOR(i, 1, n){
		ll temp = 0;
		ll l1 = dp[i][0];
		ll r1 = dp[i][1];
		temp = (req[l1-1] - req[r1]) + (ext[r1]- ext[l1-1]);
		
		if(temp > ans){
			ll idx = i;	
			ans = temp;
		}
	}

	FOR(i,1, mx){
		if(arr[i] == k){
			ans++;
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
    int t;
    preprocess();
    
    cin>>t;
    while(t--){
      compute();
    }//end while  
   
    //return 0;
}