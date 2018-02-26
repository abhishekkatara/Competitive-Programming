#include <bits/stdc++.h>

using namespace std;

#define lld long long int

bool charCheck(char str[4], char ch){
    lld i = 0;
    while(str[i] != '\0'){
        if(str[i] == ch){
            return 0;
        }
        i++;
    }
    return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    lld t;
    cin>>t;
    lld ar[t];
    while(t--){
        string str;
        cin>>str;
        lld i=0,count=0;
        char check[4] = {'0'};
  
        while(str[i] != '\0'){
            char ch = str[i];
            if(ch=='c'||ch=='h'||ch=='e'||ch=='f'){
                check[i%4]= ch;
                i++;
            }
            if(!(ch=='c'||ch=='h'||ch=='e'||ch=='f')){
                lld j=0;
                while(j!=4){
                    check[j] = '0';
                    j++;
                }
                i++;
            }
            if(!(charCheck(check,'c')) && !(charCheck(check,'h')) && !(charCheck(check,'e')) && !(charCheck(check,'f')))
                count++;
        }
        ar[t] = count;
    }

    lld size = sizeof(ar)/sizeof(ar[0]);

    for(lld i=0;i<size;i++)
        if(ar[size-i-1])
            cout<<"lovely "<<ar[size-i-1]<<endl;
        else
            cout<<"normal"<<endl;
} 