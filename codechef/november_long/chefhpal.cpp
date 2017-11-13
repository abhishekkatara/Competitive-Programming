#include <bits/stdc++.h>

using namespace std;

#define lld long long int
         
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	lld n,a,l,m,i;
 
	cin>>t;
	while(t--){
		cin>>n>>a;
		if(a>2){
			l=n/3;
			m=n%3;
			string str="abc";
			string ans="";
			for(i=0;i<l;i++)
			ans.append(str);
			for(i=0;i<m;i++)
			ans+=str[i];
			cout<<"1 "<<ans<<endl;
		}
		else if(a==1){
			string ans="";
			for(i=0;i<n;i++)
			ans+='a';
			cout<<n<<" "<<ans<<endl;
		}
		else{
			switch(n){
				case 1:
					cout<<"1 a"<<endl;
					break;
				case 2:
					cout<<"1 ab"<<endl;
					break;
				case 3:
					cout<<"2 aab"<<endl;
					break;
				case 4:
			    		cout<<"2 aabb"<<endl;
					break;
				case 5:
					cout<<"3 aaabb"<<endl;
					break;
				case 6:
					cout<<"3 aaabbb"<<endl;
					break;
				case 7:
					cout<<"3 aaababb"<<endl;
					break;
				case 8:
					cout<<"3 aaababbb"<<endl;
					break;
				 default:
					string str="aababb",ans="";
			    		l=n/6;
					m=n%6;
					for(i=0;i<l;i++)
					ans.append(str);
					for(i=0;i<m;i++)
					ans+=str[i];
					cout<<"4 "<<ans<<endl;
					break;
			}
		}
	}
} 