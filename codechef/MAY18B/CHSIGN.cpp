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
#define pnl printf("\n")
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
#define INF 1000000001
	 
LL getDP(LL dp[][2],int i,int j,int n){
	if(i>=0 && i<n){
		return dp[i][j];
	}
	return 0;
}//end getDP

int getArr(int arr[],int i,int n){
	if(i>=0 && i<n){
		return arr[i];
	}
	return INF;
}//end getArr
 
void preprocess(){
 
}//end preprocess
 
void refresh(){
 
}//end refresh
 
void compute(){
	int n;
	cin>>n;
	int arr[n];
	LL dp[n][2];
	bool ans[n][2];
 
	REP(i,n){
		cin>>arr[i];
	}
 
	REP(i,n){
		if(getDP(dp,i-1,1,n) <= getDP(dp,i-1,0,n)){
			dp[i][0] = getDP(dp,i-1,0,n);
			ans[i][0] = 0;
		}
		else{
			dp[i][0] = getDP(dp,i-1,1,n);
			ans[i][0] = 1;
		}
 
		if(arr[i] < getArr(arr,i+1,n) && arr[i] < getArr(arr,i-1,n)){
			if(getArr(arr,i-1,n) <= arr[i]+getArr(arr,i-2,n)){
				if(getDP(dp,i-2,1,n) < arr[i]+getDP(dp,i-2,0,n)){
					dp[i][1] = arr[i] + getDP(dp,i-2,0,n);
					ans[i][1] = 0;
				}
				else{
					dp[i][1] = getDP(dp,i-2,1,n);
					ans[i][1] = 1;
				}
			}
			else{
				if(getDP(dp,i-2,1,n) <= getDP(dp,i-2,0,n)){
					dp[i][1] = arr[i] + getDP(dp,i-2,0,n);
					ans[i][1] = 0;
				}
				else {
					dp[i][1] = arr[i] + getDP(dp,i-2,1,n);
					ans[i][1] = 1;
				}
			}
		}
		else {
			dp[i][1] = 0;
			ans[i][1] = 0;
		}
 
	}
	int i = n-1;
//cout<<i<<" ";
	bool f1 = false;
	if(dp[i][0] < dp[i][1]){
		f1 = 1;
	}
	while(i >= 0){
		if(!f1){
			f1 = ans[i][0];
			i--;
		}
		else{
			arr[i] *= (-1);
			f1 = ans[i][1];
			i = i-2;
		}
	}
 
	REP(i,n){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}//end compute
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	preprocess();

	cin>>t;
	while(t--){
		compute();
}//end while

//return 0;
}