#include <bits/stdc++.h>
# define mp make_pair
# define pb push_back
# define repi(i,p,q) for(long i=p;i<q;i++)
# define repd(i,p,q) for(long i=p;i>=q;i--)
# define sz(x) x.size()
# define INF 2000000000
# define MOD 1000000007

using namespace std;


typedef map<int,int> MI;
typedef pair<int,int> PI;
typedef long long int LLI;
typedef long int LI;
typedef int I;

int main() {
	int t;
	int n;
	cin >> t;
	while(t--) {
		cin >> n;
		long long answer = 0;
		long long number;
		for(int i = 0 ; i < n ; i++) {
			cin >> number;
			answer = answer + number;
		}
		cout << answer << endl;
	}
	return 0;
}

