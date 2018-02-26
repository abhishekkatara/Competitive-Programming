#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

ull p2(ull x,ull y,ull m){
    if (y == 0){
        return 1;
    }
    
    ull p = p2(x,y/2,m)%m;
    p = (p*p)%m;

    if (y%2 == 0){
    	return p;
    }
    else{
        return (x*p)%m;
    }
}

ull modInverse(ull a,ull m){
    ull temp = p2(a,m-2,m);
    return temp;
}

ull gcd(ull a,ull b){
    if (a == 0)
    	return b;
	
	return gcd(b%a,a);
}

bool powerCheck(ull x){
    return ((x&(x-1)) == 0) && x!=0;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull t;
    cin>>t;

    while(t--){
    	ull l,d,t_in;
    	cin>>l>>d>>t_in;
	      if(powerCheck(t_in))
	      {
	      	ull ar[100],j=1,T=l;
	      	ar[0]=d;
	      	int k=1;
	      	while(j<t_in)
	      	{
	           l=(l*l)%1000000007;
	      	   ar[k]=(((2*ar[k-1]*ar[k-1])%1000000007)-l)%1000000007;
	      	   j=(ull)pow(2,k);
	      	   k++;
	      	}
	      	ar[k-1]=(ar[k-1]*T)%1000000007;
	        ull ans= modInverse(l, 1000000007L);


	      if(ar[k-1]<0)
	         ar[k-1]=1000000007+ar[k-1];
	      cout<<(ar[k-1]*ans)%1000000007<<endl;}
	      else{
	      int id=(int)t_in;
	      long arr[id];
	      arr[0]=d;
	      ull T=l;
	      ull q;
	      if(id>1){
	        arr[1]=(2*d*d-l*l)%1000000007;
	       }

	      double pi=3.14159;
	      double angle=acos((double)d/l);
	      int n=(int)(pi/angle);
	      for(int j=2;j<id;j++){
	      	arr[j]=(2*d*arr[j-1]-((T*T)%1000000007)*(arr[j-2]))%1000000007;


	      }
	      for(int j=1;j<id-1;j++)
	      {
	      	l=(l*T)%1000000007;
	      }

	      ull ans= modInverse(l, 1000000007L);

	      if(arr[id-1]<0)
	        arr[id-1]=1000000007+arr[id-1];
	      cout<<(arr[id-1]*ans)%1000000007<<endl;
		}
	}
}	