#include <bits/stdc++.h>
 
using namespace std;
 
#define alpha_size 26
 
long long int filter=0;
int site1[200010];
 
int idx=0;
 
struct node{
 
	struct node* children[alpha_size];
	bool blocked[2];
	int isLeaf;
 
};
 
struct node* newNode(){
 
	struct node* newnode = (node*)malloc(sizeof(node));
 
	newnode->isLeaf=false;
	newnode->blocked[0]=false;
	newnode->blocked[1]=false;
		
 
	for (int i = 0; i < alpha_size; ++i)
	{
		newnode->children[i]=NULL;
	}
 
	return newnode;
 
}
 
int getidxex(char a){
 
	return a - 'a';
 
}
 
void insert(struct node* root,int sign,char* text){
 
	int idxex;
	struct node* n = root;
 
	for (int i = 0; i < strlen(text); ++i)
	{
		
		idxex = getidxex(text[i]);
 
		if(!n->children[idxex])
			n->children[idxex] = newNode();
 
		n->blocked[sign]=true;
		n = n->children[idxex];
 
	}
 
	n->blocked[sign]=true;
 
	if(sign==0)
		n->isLeaf = -1;
	else
		n->isLeaf = 1;
 
}
 
 
bool check(struct node* root){
 
	if(root==NULL)
		return true;
 
	struct node* n1 = root;
	struct node* n2;
	bool state=true;
 
	for(int i=0;i<alpha_size;i++){
 
		n2 = n1->children[i];
 
		if(n2!=NULL){
 
			if(n2->isLeaf==-1 && n2->blocked[0]==true && n2->blocked[1]==true){
 
				state=false;
 
			}
 
			else {
 
				state = state && check(n2);
 
			
			}
				
		}
 
	}
 
	return state;
 
}
 
 
void printFilter(struct node* root){
 
	if(root==NULL)
		return;
 
	struct node* n1 = root;
	struct node* n2;
 
	for(int i=0;i<alpha_size;i++){
 
		n2 = n1->children[i];
		
		if(n2!=NULL){
 
			if(n2->blocked[0]==true && n2->blocked[1]==true){
 
				printFilter(n2);
 
			}
 
			else if(n2->blocked[0]==true && n2->blocked[1]==false){
 
				filter++;
 
			}
 
		}
 
	}
 
 
}
 
void printString(){
 
	for (long long int i = 0; i < idx; ++i)
	{
		printf("%c",'a'+site1[i] );
	}
 
	cout<<endl;
				
 
}
 
void printTrie(struct node* root){
 
	if(root==NULL)
		return;
 
	struct node* n1 = root;
	struct node* n2;
 
	for(int i=0;i<alpha_size;i++){
 
		n2 = n1->children[i];
		site1[idx]=i;
		idx++;
 
		if(n2!=NULL){
 
			if(n2->blocked[0]==true && n2->blocked[1]==true){
 
				printTrie(n2);
 
			}
 
			else if(n2->blocked[0]==true && n2->blocked[1]==false){
 
				printString();
 		}

		}
 
		idx--;
 
	}
 
}
 
int main(){
 
	long long int n;
	node* root = newNode();
	int sig;
	filter=0;
 
	cin>>n;
 
	char sign;
	char* site=(char*)(malloc(sizeof(char)*200010));
 
	
	for(long long int i=0;i<n;i++){
 
		cin>>sign;
		scanf("%s",site);
 
		if(sign=='+')
			sig = 1;
		else 
			sig = 0;
 
		insert(root,sig,site);
 
	}
 
	printFilter(root);
 
	site[0]='\0';
	idx=0;
 
	if(filter!=0){
		cout<<filter<<endl;
		printTrie(root);	
	}
	
	else
		cout<<"-1"<<endl;
 
 
}