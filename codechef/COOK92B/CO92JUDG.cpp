#include <bits/stdc++.h>
using namespace std;
#define lld long long int
int main(){
	lld t;
	cin>>t;
	while(t--){
		lld n,x;
		cin>>n;
		multiset<lld,greater<lld>> a1,a2;
		for(lld j=0;j<n;j++){
			cin>>x;
			a1.insert(x);
		}

			for(lld j=0;j<n;j++){
				cin>>x;
				a2.insert(x);
			}
				a1.erase(a1.begin());
				a2.erase(a2.begin());
	 
				multiset<lld>::iterator i;

				lld sum=0,sum1=0;
				for(i=a1.begin();i!=a1.end();i++) sum = sum + *i;

					for(i=a2.begin();i!=a2.end();i++) sum1 = sum1 + *i;

						if(sum1<sum) {
							cout<<"Bob"<<endl;
						}
	 
						else if(sum1>sum) {
							cout<<"Alice"<<endl;
						}

						else {
							cout<<"Draw"<<endl;
						}
	 
						a1.clear();
						a2.clear();
	}
}