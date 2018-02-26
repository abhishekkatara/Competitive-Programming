#include <bits/stdc++.h>
using namespace std;
#define endl '\n';


inline int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

inline int cDiv(int a,int b)
{
    // find gcd of a,b
    int n = gcd(a, b);
 
    // Count divisors of n.
    int result = 0;
    for (int i=1; i<=sqrt(n); i++)
    {
        // if 'i' is factor of n
        if (n%i==0)
        {
            // check if divisors are equal
            if (n/i == i)
                result += 1;
            else
                result += 2;
        }
    }
    return result;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int T,N;
	cin>>T;
	/*vector<vector<int> > arr(1001,vector<int>(1001));
	for(int i=1;i<=N;i++)
		arr[1][i]=arr[i][1]=1;
	arr[1][1]=0;
	int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
	for(int i=2;i<=1000;i++){
		arr[i][i]=0;
		if(binary_search(primes,primes+167,i)){
			for(int j=i+1;j<=1001;j++){
				if(j%i==0)
					arr[i][j]=arr[j][i]=2;
				else
					arr[i][j]=arr[j][i]=1;
			}
		}
		else{
			arr[i][j]=arr[j][i]=cDiv(i,j);
		}
	}*/

	while(T--){
		cin>>N;
		vector<vector<int> > arr(N+1,vector<int>(N+1));
		for(int i=1;i<=N;i++){
			arr[i][i]=0;
			for(int j=i+1;j<=N;j++)
				arr[i][j]=arr[j][i]=cDiv(i,j);
		}
		/*cout<<"arr:\n";
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++)
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}*/
		vector<vector<int> > tarr(N+1,vector<int>(N+1));
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++)
				cin>>tarr[i][j];
		}
		/*cout<<"\n\ntarr:\n";
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++)
				cout<<tarr[i][j]<<" ";
			cout<<endl;
		}*/
		vector<int> check(N+1,0);
		vector<bool> halla(N+1,0);
		for(int i=1;i<=N;i++){
			sort(tarr[i].begin(),tarr[i].end());
			for(int j=1;j<=N;j++){
				sort(arr[j].begin(),arr[j].end());
				if(arr[j]==tarr[i]){
					if(halla[j]==0){
						check[i]=j;
						halla[j]=1;
						break;
					}
				}
			}
		}
		for(int i=1;i<=N;i++)
			cout<<check[i]<<endl;
	}
}