#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define lowbit(x) ((x)&(-(x)))
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , ans[maxn];
int par[maxn] , sz[maxn] , indeg[maxn] , outdeg[maxn];
vector < int > comp[maxn] , adj[maxn] , radj[maxn];
set < int > st;

int getpar(int v){
    return((v == par[v])?v:par[v]=getpar(par[v]));
}

void merge(int v , int u){
    v = getpar(v) , u = getpar(u);
    if(u == v) return;
    if(sz[u] > sz[v]) swap(u , v);
    par[u] = v , sz[v]+=sz[u];
}

int main(){
    migmig
    ms(ans , -1);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ ){
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> v >> u;
        merge(u , v);
        adj[v].pb(u);
        radj[u].pb(v);
        indeg[u]++;
        outdeg[v]++;
    }
    for(int i = 1 ; i <= n ; i ++){
        comp[getpar(i)].pb(i);
    }
    int cur = n;
    for(int i = 1 ; i <= n ; i ++){
        if(outdeg[i] == 0){
            st.insert(i);
        }
    }
    while(!st.empty()){
        auto v = *st.rbegin();
        st.erase(v);
        ans[v] = cur--;
        for(auto u : radj[v]){
            outdeg[u]--;
            if(outdeg[u] == 0){
                st.insert(u);
            }
        }
    }
    for(int i = 1 ; i <= n ; i ++){
        cout << ans[i] << ' ';
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
