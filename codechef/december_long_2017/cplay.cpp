#include <bits/stdc++.h>

using namespace std; 

#define lld long long int 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string str;
    while(cin>>str){
        int i,j,k,l,m;
        int score1=0,score2=0;
        string a,b;
        for(i=0;i<20;i+=2){
            a=a+str[i];
        }
        for(i=1;i<20;i+=2){
            b=b+str[i];
        }  
        int flag=0;
        
        for(i=0,j=0;i<5;){ 
        	if((score1>score2+5-j)||(score2>score1+5-i)){
        		flag=1;
            	break;
        }
            
            if(a[i++]=='1'){
             score1++;
            }
            
            if((score1>score2+5-j)||(score2>score1+5-i)){
            	flag=1;
                break;
            }
            
            if(b[j++]=='1'){
            	score2++;
            }
            if((score1>score2+5-j)||(score2>score1+5-i)){
            	flag=1;
                break;
            }
        }
        
        if(flag==1 && score1!=score2){
            if(score1>score2){
                cout<<"TEAM-A "<<i+j<<endl;
            }

            else{
                cout<<"TEAM-B "<<i+j<<endl;
            }
        }
        else
        {
            for(i=5;i<10;i++){
            	if(a[i]=='1'&&b[i]=='0'){
                cout<<"TEAM-A "<<2*i+2<<endl;
                break;
            }
                if(a[i]=='0'&&b[i]=='1'){
                    cout<<"TEAM-B "<<2*i+2<<endl;
                    break;
                }   
            }
            if(i==10){
            	cout<<"TIE"<<endl;
    		}
        }
    }    
}