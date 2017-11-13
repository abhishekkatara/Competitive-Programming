#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

#define N 100001

lld n,m,bank[N];
vector<lld> g[N];
vector<lld> ans;
bool visited[N];
 
void dfs(lld n,lld champ)
{
   visited[n]=true;
   if(bank[n]==1)
    champ=1;
   if(champ==1)
    ans.push_back(n);
   for(lld i=0;i<g[n].size();i++)
   {
       if(!visited[g[n][i]]){
        dfs(g[n][i],champ);
       }
   }
   visited[n]=false;
}
 
int main()
{
    lld t,i;
    cin>>t;
    while(t--)
    {
        for(i=0;i<N;i++){
            g[i].clear();
            bank[i]=0;
        }
        cin>>n>>m;
        for(i=1;i<n;i++)
        {
            lld u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(i=1;i<=m;i++)
        {
            lld a,b;
            cin>>a>>b;
            if(a==1)
                bank[b]=1;
            else
            {
                ans.clear();
                dfs(b,0);
                sort(ans.begin(),ans.end());
                if(ans.size()==1)
                    cout<<"-1"<<endl;
                else
                    cout<<(ans[ans.size()-2])<<endl;
            }
        }
    }
    return 0;
} 