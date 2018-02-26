#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lld t, cnt = 0;
    cin>>t;
    vector <lld> v(t);
    
    while(t != cnt){
        lld n,m,x,k;
        cin>>n>>m>>x>>k;
        string str;
        cin>>str;

        if(str.size() != k){
            v[cnt] = 0;
        }

        else if(n > x*m){
            v[cnt] = 0;
        }

        else{
            lld even = 0,odd = 0,i = 0;
            while(str[i] != '\0'){
                if(str[i] == 'O'){
                    odd++;
                }

                if(str[i] == 'E'){
                    even++;
                }
                i++;
            }
            
            while(n && m>0){
                if(m%2 == 0){
                    if(even!=0 && x>even){
                        n -= even;
                        even = 0;
                    }

                    else if(even!=0){
                        even -= x;
                        n -= x;
                    }
                }
                else{
                    if(odd!=0 && x>odd){
                        n -= odd;
                        odd = 0;
                    }

                    else if(odd != 0){
                        odd -= x;
                        n -= x;
                    }
                }
                m--;
            }

            if(m>=0 && n<=0){
                v[cnt] = 1;
            }

            else{
                v[cnt] = 0;
            }
        }
        cnt++;
    }
    for(int i=0;i<t;i++)
        if(v[i] == 0){
            cout<<"no"<<endl;
        }
        
        else{
            cout<<"yes"<<endl;
        }
} 