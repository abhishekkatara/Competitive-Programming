#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#undef int
#define long int
#define unsigned long long ull
#define MOD 1000007

struct node{
	int lower;
	int upper;
	map<int,int> factor;
	node *left,*right;
};


vector<int> arr;

set<int> prime_vec;
int max_prime = 0,prime_size=0;


	//Segmented Sieve

void simple(int limit, vector<int> &prime)
{
	bool mark[limit+1];
	memset(mark, true, sizeof(mark));
	
	for (int p=2; p*p<limit; p++)
	{
		
		if (mark[p] == true)
		{
			
			for (int i=p*2; i<limit; i+=p)
				mark[i] = false;
		}
	}
	 
	for (int p=2; p<limit; p++)
	{
		if (mark[p] == true)
		{
			prime.push_back(p);
	//i is prime
			if(p>max_prime)
				max_prime = p;
			prime_vec.insert(p);
			++prime_size;
		}
	}
}

int segm(int n)
{
	int limit = floor(sqrt(n))+1;
	vector<int> prime;
	simple(limit, prime);
	
	int low = limit;
	int high = 2*limit;
	
	while (low < n)
	{
		bool mark[limit+1];
		memset(mark, true, sizeof(mark));
		
		for (int i = 0; i < prime.size(); i++)
		{
			int l_limit = floor(low/prime[i]) * prime[i];
			if (l_limit < low)
				l_limit += prime[i];
			
			for (int j=l_limit; j<high; j+=prime[i])
				mark[j-low] = false;
		}
		
		for (int i = low; i<high; i++)
			if (mark[i - low] == true)
			{
				if(i>max_prime)
					max_prime = i;
				prime_vec.insert(i);
				++prime_size;
			}
			
			low = low + limit;
			high = high + limit;
			if (high >= n) high = n;
		}
		return max_prime;
	}
	
	void calc(int n,map<int,int>& factor_map)
	{
		set<int>::iterator itr = prime_vec.begin();
		
		for(;itr!=prime_vec.end();++itr)
		{
			int pr = *itr;
			int nm = n;
			int expo = 0;
			while( nm % pr == 0 ) {
				++expo;
				nm/=pr;
			}
			factor_map.insert(make_pair(*itr,expo));
		}
	}
	
	void sum_fact(node *left,node *right,map<int,int>& factor_map)
	{
		map<int,int>::iterator itr_left = left->factor.begin();
		map<int,int>::iterator end_left = left->factor.end();
		map<int,int>::iterator itr_right = right->factor.begin();
		map<int,int>::iterator end_right = right->factor.end();
		
		while (itr_left!=end_left || itr_right!=end_right)
		{
			if(itr_left!=end_left&& itr_right!=end_right)
			{
				if(itr_left->first==itr_right->first)
				{
					factor_map.insert(make_pair(itr_left->first,(itr_left->second+itr_right->second)));
					++itr_left;++itr_right;
				}
				else if(itr_left->first<itr_right->first)
				{
					factor_map.insert(make_pair(itr_left->first,itr_left->second));
					++itr_left;
				}else{
					factor_map.insert(make_pair(itr_right->first,itr_right->second));
					++itr_right;
				}
				
			}else if(itr_left!=end_left){
				factor_map.insert(make_pair(itr_left->first,itr_left->second));
				++itr_left;
			}
			else{
				factor_map.insert(make_pair(itr_right->first,itr_right->second));
				++itr_right;
			}
			
		}
	}
	
	
	node* create_seg(int lower,int upper)
	{
		assert(lower<=upper);
		node *ptr = new node;
		ptr->lower = lower;
		ptr->upper = upper;
		ptr->left = ptr->right = NULL;
		
		if((lower+1)==upper)
		{
			ptr->left = create_seg(lower,lower);
			ptr->right = create_seg(upper,upper);
			sum_fact(ptr->left,ptr->right,ptr->factor);
		}
		else if(lower == upper)
		{
			assert(lower>0);
			calc(*(arr.begin()+lower-1),ptr->factor);
		}
		else{
			int mid = (lower+upper)/2;
			ptr->left = create_seg(lower,mid);
			ptr->right = create_seg(mid+1,upper);
			sum_fact(ptr->left,ptr->right,ptr->factor);
		}
		return ptr;
	}
	
	int find_expo(node *root,int &l,int &r,int &x,int &y)
	{
	 
		if(!root || root->upper<l || root->lower>r || l>r || x>y)
		{
			return 0;
		}
		else if((root->lower==l&&root->upper<=r)||(root->lower>=l&&root->upper==r)||(root->lower>l && root->upper<r))
		{
			int expo = 0;
			for(int i=x;i<=y;++i)
			{
				auto itr = root->factor.find(i);
				if(itr!=root->factor.end() && itr->first == i)
					expo+=itr->second;
			}
			return expo;
		}
		else if(l>=root->lower || l<= root->upper)
		{
			int val1 = find_expo(root->left,l,r,x,y);
			int val2 = find_expo(root->right,l,r,x,y);
			return val1+val2;
		}
		
		
	}
	
	void deletetreee(node* root)
	{
		if(root==NULL)
			return;
		deletetreee(root->left);
		deletetreee(root->right);
		delete root;
	}
	
	#undef int
	
	int main()
	{
	#undef int
	#define int long
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int size,max_el=0;
		cin>>size;
		for(int i=0;i<size;++i)
		{
			int temp;
			cin>>temp;
			arr.push_back(temp);
			if(temp>max_el)
				max_el = temp;
		}
		
		segm(max_el);
		
		node *root= create_seg(1, size);
		
		int querry;
		cin>>querry;
		for(int i=0;i<querry;++i)
		{
			int l,r,x,y;
			cin>>l>>r>>x>>y;
			cout<<find_expo(root,l,r,x,y)<<endl;
		}
		return 0;
	}