/******************************************
* AUTHOR: Abhishek Katara 				  *
* INSTITUITION: IIIT Vadodara 			  *
******************************************/
	 
#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007LL
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
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int *a,int *b){int temp;temp=*a;*a=*b;*b=temp;}
ULL gcd(ULL a,ULL b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;
if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}
#define SIZE 1000001
	 
	 
void preprocess(){
}//end prepreprocess
 
void refresh(){
}//end refresh
 
void compute(){
	int arr[10001];
	int n,k;
	si(n);
	si(k);
 
	REP(i,n){
		si(arr[i]);
	}
 
	if(n == 1){
		cout<<"NO"<<endl;
	}
	else{
		int id = 0,id1 = 0;
		int s1 = 0,s2 = 0;
		int arr1[10001],arr2[10001];
		REP(i,n){
			if(i%2==0){
				arr1[id] = arr[i];
				id++;
				s1 += arr[i];
			}
			else{
				arr2[id1] = arr[i];
				id1++;
				s2 += arr[i];
			}
		}
 
		sort(arr1,arr1+id);
		sort(arr2,arr2+id1);
 
		if(k==0){
			if(s2<=s1){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
			}
		}
		else{
			int temp1 = k;
			int f1 = id-1,f2 = 0;
			while(f1>=0 and f2<id1 and temp1!=0 and arr1[f1]>arr2[f2]){
//swap(arr1[f1],arr2[f2]);
				int var = arr1[f1];
				arr1[f1] = arr2[f2];
				arr2[f2] = var;
				f1--;
				f2++;
				temp1--;
			}
			int s1=0,s2=0;
 
			REP(i,id){
				s1 += arr1[i];
			}
			REP(i,id1){
				s2 += arr2[i];
			}
 
			if(s2<=s1){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
			}
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

return 0;
}