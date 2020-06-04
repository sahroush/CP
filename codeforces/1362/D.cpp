#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

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

int n , m;
vector < int > adj[maxn];
pii t[maxn];
int inf = 0;
vector < int > ans;
int val[maxn];
int want[maxn];
set < int > st;

bool ad(int v){
    ans.pb(v);
    st.clear();
    for(auto u : adj[v])
        st.insert(val[u]);
    int mn = 1;
    for(;;mn++)
        if(!st.count(mn))
            break;
    val[v] = mn;
    return(mn == want[v]);
}

int main(){
    migmig
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ms(val , 63);
    inf = val[0];
    for(int i = 1 ; i <= n ; i ++){
        t[i].second = i;
        cin >> t[i].first;
        want[i] = t[i].first;
    }
    sort(t + 1 , t + 1 + n);
    for(int i = 1 ; i <= n ; i ++){
        if(!ad(t[i].second))
            dokme(-1)
    }
    for(int i : ans)
        cout << i << ' ';
    return(0);
}