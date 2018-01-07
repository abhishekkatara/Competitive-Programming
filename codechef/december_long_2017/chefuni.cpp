#include <bits/stdc++.h>

using namespace std;

#define lld long long int

lld  x, y, z, a, b, c;

lld same(lld x){
	lld t = min(3*b,2*c);
	return(t*(x/2) + (1&x)*c);
}

lld case1(lld p){
	if (x==y&&y==z){
		return(p+same(x));
	}

	lld c2 = min(x/2,y/3);

	p += c2 * min(2*c + b,4*b);
	x -= 2*c2; 
	y -= 3*c2; 
	z -= 3*c2;

	if(x){
		p += same(x); 
		y -= x; 
		z -= x;
	}

	p += y*b + (z-y)*a;
	return p;
}

lld case2(lld p){
	return(p + y*b + (z-y)*a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	int tc;
	cin>>tc; 
	while(tc--){
		cin>>x>>y>>z>>a>>b>>c;

	if(x>y){
		swap(x,y);
	}
	if(y>z){ 
		swap(y,z);
	}
	if(x>y){ 
		swap(x,y);
	}

	b = min(2*a,b); 
	c = min(a+b,c);

	if(x==y&&y==z){
	 cout<<same(x)<<endl;
	}

	lld c1 = z-y;
	
	if(c1<x){
		x -= c1;
		y -= c1;
		z -= 2*c1;

		cout<<case1(c1 * min(2*b,a+c))<<endl;
	} 

	else{
		y -= x; 
		z -= x*2;
		cout<<case2(x * min(2*b,a+c))<<endl;
	}
	}
	return 0;
}


/*
update MID
/*if (Tag[o]) {
			Mn[o << 1] += Tag[o]; Mn[o << 1 | 1] += Tag[o];
			Tag[o << 1] += Tag[o]; Tag[o << 1 | 1] += Tag[o];
			Tag[o] = 0;
		}*/

//if mid<R const int V = 2010;
		//Mn[o] = min(Mn[o << 1], Mn[o << 1 | 1]);
