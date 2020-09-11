/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 1e5 + 100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll q;
ll n , m;
vector < ll > adj[maxn];
ll val[maxn];
vector < ll > p;

ll dfs(ll v = 1 , ll par = 0){
    ll sub = 1;
    for(auto u : adj[v])
        if(u!=par)
            sub += dfs(u , v);
    val[v-1] = ((sub) * (n - sub));
    return(sub);
}//wtf

int32_t main(){
    migmig
    cin >> q;
    while(q --){
        cin >> n;
        p.clear();
        for(ll i = 1 ; i <= n ; i ++)
            adj[i].clear();
        for(ll i = 1 ; i < n ; i ++){
            ll u  , v;
            cin  >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs();
        sort(val + 1 , val + n);
        reverse(val + 1 , val + n);
        ll ans = 0;
        cin >> m;
        ll x;
        for(ll i = 0 ; i < m ; i ++)
            cin >> x , p.pb(x);
        sort(p.begin() , p.end());
        if(m < n - 1){
            for(ll i = 1 ; i < n ; i ++)
                if(p.size()) val[i] = (val[i]%mod * p.back()%mod)%mod,p.pop_back();
        }
        else{
            reverse(p.begin() , p.end());
            for(ll i = n-1 ; i  ; i --)
                val[i] = (val[i]%mod * p.back()%mod)%mod ,p.pop_back();
            while(p.size())
                val[1] = (val[1]%mod * p.back()%mod)%mod,p.pop_back();
        }
        for(ll i = 1 ; i < n ; i ++)
            ans = (ans%mod + val[i]%mod)%mod;
        cout << ans%mod << endl;
    }
    return(0);
}