#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

ll n ,q;
ll prt[maxn];
ll par[maxn];
ll sz[maxn];
set < pair < ll , pll > > st;
ll ans = 0;

ll getpar(int v){
    return((v==par[v])?v:par[v] = getpar(par[v]));
}

void merge(int u , int v){
    u = getpar(u) , v = getpar(v);
    if(v == u){
        return;
    }
    if(sz[u] > sz[v]){
        swap(u , v);
    }
    par[u] = v;
    ans -= sz[u]*(sz[u]-1)/2 + sz[v]*(sz[v]-1)/2;
    sz[v]+=sz[u];
    ans+=sz[v]*(sz[v]-1)/2;
}
int main(){
    migmig
    cin >> n >> q;
    for (int i = 0 ; i < n-1 ; i ++){
        int u , v , w;
        cin >> u >> v >> w;
        st.insert({w , {u , v}});
    }
    for (int i = 1 ; i <= n ; i ++){
        sz[i] = 1;
        par[i] = i;
    }
    for (int i = 1 ; i < maxn ; i ++){
        if(st.size()){
            while(st.size() and (*st.begin()).first == i){
                auto p = *st.begin();
                st.erase(p);
                merge(p.second.first , p.second.second);
            }
        }
        prt[i] = ans;
    }
    while(q--){
        int x;
        cin >> x;
        cout << prt[x] << ' ';
    }

    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
