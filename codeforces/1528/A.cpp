#include<bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define pb push_back
#define fast cin.tie(0),ios::sync_with_stdio(0)

typedef long long ll;

int lrs[2][200005];
vector < int > adj_list[200005];
ll dp[2][200005];

void dfs(int v,int p)
{
    dp[0][v] = dp[1][v] = 0;
    for(auto u:adj_list[v])
    {
        if(u==p) continue;

        dfs(u,v);
        
        dp[0][v]+=max(dp[0][u]+abs(lrs[0][v]-lrs[0][u]), dp[1][u]+abs(lrs[0][v]-lrs[1][u]));
        dp[1][v]+=max(dp[0][u]+abs(lrs[1][v]-lrs[0][u]), dp[1][u]+abs(lrs[1][v]-lrs[1][u]));
    }
}

void solve()    //check t
{
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        cin>>lrs[0][i]>>lrs[1][i];
        adj_list[i].clear();
    }
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }
    dfs(1 , 0);
    cout<<max(dp[1][1],dp[0][1])<<endl;
}

int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
