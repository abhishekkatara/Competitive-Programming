/******************************************
* AUTHOR: Abhishek Katara 				  *
* INSTITUITION: IIIT Vadodara 			  *
******************************************/
	 
#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define LL long long
#define ULL unsigned long long
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
#define pn_l printf("\n")
#define REP(i,n) for(LL i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))
#define all(v) v.begin(),v.end()
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int a,int b){int temp;temp=a;a=b;b=temp;}
ULL gcd(ULL a,ULL b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;
if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}
ULL mult1(LL a,LL b){LL res = 0;a %= MOD; while (b){if (b & 1){res = (res + a) % MOD;}
a = (2 * a) % MOD;b >>= 1; }return res;}
#define SIZE 100001
LL fib[SIZE];
 
 
LL preprocess(LL ar[SIZE]){
	ar[0] = 0;
	ar[1] = 1;
	FOR(i,2,SIZE){
		ar[i] = (ar[i-1]%MOD + ar[i-2]%MOD)%MOD;
	}
	return ar[SIZE];
}//end preprocess
 
void refresh(){
}//end refresh
 
void compute(){
	int n,m;
	cin>>m>>n;
	LL a[m],b[m];
	LL s1 = 0,s2 = 0;
	
	REP(i,m){
		cin>>a[i];
		s1 += (a[i]%MOD)%MOD;
	}
	s1 %= MOD;
	REP(i,m){
		cin>>b[i];
		s2 += (b[i]%MOD)%MOD;
	}
	s2 %= MOD;
//cout<<s1<<" "<<s2<<endl;
	LL k = mult1(fib[n-2],s1) + mult1(fib[n-1],s2);
//cout<<k<<endl;
	
	if(n == 1){
		cout<<s1*m<<endl;
	}
	else if(n == 2){
		cout<<s2*m<<endl;
	}
	else{
		LL result = mult1(m,k);
		cout<<result<<endl;
	}
}//end compute
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	preprocess(fib);
	
	cin>>t;
	while(t--){
		compute();
}//end while
	
	//return 0;
}