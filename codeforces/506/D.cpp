#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =1e5+5;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m , q;
//vector < pii > adj[maxn];
vector < int > ncol[maxn];
unordered_map < int  , int > par[maxn] ;
map < pii , int > res;

inline int getpar(int v , int c){
    if(par[c].find(v)==par[c].end()){
        return(v);
    }
    return(par[c][v] = getpar(par[c][v] , c));
}

inline void merge(int v , int u , int c){
    v = getpar(v , c) , u = getpar(u , c);
    if(u == v) return;
    par[c][v] = u;
}

int main(){
    //migmig
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++){
        int u , v, c;
        cin >> u >> v >> c;
        ncol[v].pb(c);
        ncol[u].pb(c);
        merge(v , u , c);
    }
    for (int i = 1 ; i <= n ; i ++){
        sort(ncol[i].begin() , ncol[i].end());
        ncol[i].resize(unique(ncol[i].begin() , ncol[i].end()) - ncol[i].begin());
    }
    cin >> q;
    while(q --){
        int u , v;
        cin >> u >> v;
        if(ncol[u].size() < ncol[v].size()){
            swap(v , u);
        }
        if(res.find(pii(u , v))!=res.end()){
            cout << res[pii(u , v)] << endl;
            continue;
        }
        int ans = 0;
        for (int i = 0 ; i < ncol[v].size() ; i ++){
            int a = getpar(v , ncol[v][i]);
            int b = getpar(u , ncol[v][i]);
            if(a == b) ans++ ;
        }
        res[pii(u , v)] = ans;
        cout << ans << endl;
    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
