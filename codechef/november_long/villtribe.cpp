#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    char arr[100001];
    int total;
    while(t--){

        int result[2]={0,0};
        scanf("%s",arr);
        char flag;

        if(arr[0]=='A'){
             flag='A';
        }
        else if(arr[0]=='B'){
             flag='B';
        }       
        else{ 
            flag='.';
        }
        lld i=0;
        total=0;

        while(i < strlen(arr)){
            if(arr[i]=='.'){total+=1;}
            else if(arr[i]==flag){result[flag-'A']+=total+1;total=0;}
            else if(arr[i]!=flag){total=0;flag=arr[i];result[flag-'A']+=1;}
            i++;
        }
        cout<<result[0]<<" "<<result[1]<<endl;
    }
} 