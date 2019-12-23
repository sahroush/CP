#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =4e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

struct edge{
    int u , v;
};

int n;
vector < edge > vec[maxn];
int a[maxn] , sum = 0;
int par[maxn] , sz[maxn] , ans;


int getpar(int v){
    if(v == par[v]){
        return(v);
    }
    return(par[v] = getpar(par[v]));
}
void merge(int x , int y){
    x = getpar(x) , y = getpar(y);
    if(x == y){
        return;
    }
    if(sz[y] > sz[x]){
        swap (x , y);
    }
    sz[x] += sz[y];
    par[y] = x;
    a[x] += a[y];
}
bool chk(int v){
    if(v == getpar(v)){
        if(sz[v] > sum - a[v]){
            return(1);
        }
    }
    return(0);
}

int main(){
    migmig
    cin >> n;
    for (int i = 1 ; i < n ; i ++){
        int v , u , w;
        cin >> v >> u >> w;
        edge e;
        e.v = v;
        e.u = u;
        vec[w].pb(e);
    }
    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        par[i] = i;
        sz[i] = 1;
        sum += a[i];
    }
    for (int i = 1 ; i <= 10000 ; i ++){
        bool f = 1;
        for (int j = 1 ; j <= n ; j ++){
            if(chk(j)){
                f = 0;
            }
        }
        if(f){
            ans = i;
        }
        for (auto it : vec[i]){
            merge(it.v , it.u);
        }
    }
    cout << ans;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
