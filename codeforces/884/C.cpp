#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =3e6+1000;
const ll mod = 998244353;
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

ll n;
int p[maxn];
int par[maxn];
ll sz[maxn];
int comps;
ll ans = 0;
bool mark[maxn];

int getpar(int v){
    return((par[v] == v)?v:par[v]=getpar(par[v]));
}

void merge(int u , int v){
    u = getpar(u) , v = getpar(v);
    if(u == v){
        return;
    }
    comps--;
    if(sz[u] > sz[v]){
        swap(u , v);
    }
    par[u] = v;
    sz[v]+=sz[u];
}

int main(){
    migmig
    cin >> n;
    comps = n;
    for (int i = 1 ; i <= n ; i ++){
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1 ; i <= n ; i ++){
        cin >> p[i];
        merge(i , p[i]);
    }
    //indeg[i] = outdeg[i] = 1
    //ye raas ke behesh yal midim ooni ke behesh dasht be ooni ke azash kandim mire taa
    //ghanooni bemoone
    //pas ma mitoonim dota cycle ro merge konim
    // agar kolesh cycle bood --> n*(n - 1)/2
    if(comps == 1){
        dokme(n*n);
    }
    vector < ll > vec;
    for (int i = 1;  i <= n ; i ++){
        if(!mark[getpar(i)]){
            mark[par[i]  ] = 1;
            vec.pb(sz[par[i]]);
        }
    }
    sort(vec.begin() , vec.end());
    reverse(vec.begin() , vec.end());
    ans = (vec[0] + vec[1])*(vec[0] + vec[1]);
    for (int i = 2 ; i < vec.size() ; i ++){
        ans+=(vec[i]*vec[i]);
    }
    cout << ans;


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
