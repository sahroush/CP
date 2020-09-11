/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

set < pii > st;
vector < pii > adj[maxn];
ll n,s;
ll sum;
int q;
ll sub[maxn];
ll val[maxn];

ll dfs(int v = 1 , int par = 0 , ll w = 0){
    sub[v] = 0;
    for(auto [u , w] : adj[v])
        if(u!=par)
            sub[v] += dfs(u , v , w);
    if(sub[v] == 0)sub[v]=1;
    val[v] = w;
    if(v > 1)st.insert({((w+1)/2) * sub[v] , v});
    sum += w * sub[v];
    return(sub[v]);
}

int32_t main(){
    migmig
    cin >> q;
    while(q --){
        st.clear();
        sum = 0;
        cin >> n >> s;
        for(int i = 1; i <= n ; i ++)
            adj[i].clear();
        for(int i = 1 ; i < n ; i ++){
            ll u , v, w;
            cin >> u >> v >> w;
            adj[u].pb({v , w});
            adj[v].pb({u , w});
        }
        dfs();
        ll ans = 0;
        while(sum > s){
            ans ++;
            auto r = *st.rbegin();
            st.erase(r);
            int v = r.second;
            sum -= r.first;
            val[v]/=2;
            st.insert({((val[v]+1)/2) * sub[v] , v});
        }
        cout << ans << endl;
    }
    return(0);
}