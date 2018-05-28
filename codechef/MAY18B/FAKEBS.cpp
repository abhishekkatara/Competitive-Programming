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
#define SIZE 1000001
	 
	 
void preprocess(){
	}//end prepreprocess
	 
void refresh(){
}//end refresh
 
void compute(){
	LL n,q;
	cin>>n>>q;
	vector<LL> v(n,0),v1;
 
	REP(i,n){
		cin>>v[i];
	}
	map<LL,LL> m1,m2;
 
	REP(i,n){
		m1[v[i]] = i;
	}
	v1 = v;
	sort(v1.begin(), v1.end());
 
	REP(i,n){
		m2[v1[i]] = i;
	}
 
	while(q--){
		LL x;
		cin>>x;
 
		LL idx = m1[x], pos = m2[x];
		LL s = pos,l = n-pos-1;
 
		LL res = 0,n_l = 0,n_s = 0;
		LL start = 0,mid = 0, end = v.size()-1;
 
		while(start <= end && l + n_l >= 0 && s + n_s >= 0){
			mid = (start + end)/2;
			if(mid == idx){
				break;
			}
			else if(mid < idx){
				if(v[mid] > x){
					res++;
					s--;
					l--;
					n_l++;
				}
				else{
					s--;
				}
				start = mid+1;
			}
			else{
				if(v[mid] < x){
					res++;
					s--;
					n_s++;
					l--;
				}
				else{
					l--;
				}
				end = mid-1;
			}
		}
 
		res -= min(n_l,n_s);
 
		if(n_l+l < 0 || n_s+s < 0 || res > min(pos,n-pos-1)){
			cout<<-1<<endl;
		}
		else{
			cout<<res<<endl;
		}
	}
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