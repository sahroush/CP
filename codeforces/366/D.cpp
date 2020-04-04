#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e3+100;//AmShZ
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);
}

struct edge{
    int l , r , u;
};

int n , m;
vector < edge > adj[maxn] , yal_haa;
int fix_l , fix_r;
bool mark[maxn];

void dfs(int v){
    mark[v] = 1;
    for (auto u : adj[v]){
        if(!mark[u.u]){
            if(u.l <= fix_l and u.r>=fix_r){
                dfs(u.u);
            }
        }
    }
}

bool chk(int x){
    for(auto i : yal_haa){
        fix_l = i.l;
        fix_r = i.l+x-1;
        ms(mark , 0);
        dfs(1);
        if(mark[n]){
            return(1);
        }
    }
    return(0);
}

int main(){
    migmig
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++){
        int u , v , l , r;
        cin >> u >> v >> l >> r;
        edge e;
        e.l = l , e.r = r;
        e.u = u;
        adj[v].pb(e);
        e.u = v;
        adj[u].pb(e);
        yal_haa.pb(e);
    }
    int l = 0 , r =1e7;
    while(r - l > 1){
        int mid = (l + r)/2;
        if(chk(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    if( l == 0){
        cout <<  "Nice work, Dima!";
    }
    else{
        cout << l;
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
