#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define SIZE 200005
#define S_SIZE 100001

int main() 
{
    lld n,k,ans;
    lld s[S_SIZE];
    lld hmap[SIZE];

    int t;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;

        for(int i=0;i<=n+k;i++) { hmap[i]=0; }
        
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            hmap[s[i]]++;
        }

        int i=0,cnt=1;
        
        while(cnt<=k)
        {
            if(hmap[i]==0)
            {
                hmap[i]++;
                cnt++;
            }
            i++;
        }
        i=0;

        while(i<=n+k+1)
        {
            if(hmap[i]==0)
            {
                ans=i;
                break;
            }
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}