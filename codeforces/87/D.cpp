#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =3e5+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

struct edge{
    ll x , y , w , k;
};

ll n , l , frnt;
ll val[maxn] , par[maxn] , c[maxn];
edge e[maxn];
ll mark[maxn];
ll res[maxn];
ll s1 , s2 , s , t;
vector<ll> vec[maxn] , vec2[maxn];
map < ll , ll > mp;

ll getpar(ll v){
    if(v == par[v]){
        return(v);
    }
    par[v] = getpar(par[v]);
    return(par[v]);
}

bool cmp(edge i , edge j){
    return(i.w < j.w);
}

void merge(ll x, ll y) {
    x = getpar(x);
    y = getpar(y);
    val[y] += val[x];
    par[x] = y;
}

ll dfs2(ll v, ll pre) {
    ll t = 0;
    mark[v] = 2;
    for (ll i = 0; i < vec[v].size(); i ++) {
        ll u = vec[v][i];
        if (mark[u] == 1) {
            t += dfs2(u, vec2[v][i]);
        }
    }
    t += c[v];
    if (pre != -1) {
        res[pre] += t * (s - t);
    }
    return (t);
}

void dfs(ll v){
    s += c[v];
    mark[v] = 1;
    if (vec[v].size() == 1) {
        l = v;
    }
    for (ll i = 0; i < vec[v].size(); i ++) {
        ll u = vec[v][i];
        if (mark[u] == 0) {
            dfs(u);
        }
    }
}

int main(){
    migmig
    cin >> n;
    memset(mark , 0 , sizeof mark);
    for (ll i = 0 ; i  < maxn ; i ++){
        par[i] = i;
        val[i] = 1;
    }
    for (ll i = 0 ; i < n-1 ; i ++){
        cin >> e[i].x >> e[i].y >> e[i].w;
        e[i].x-- , e[i].y--;
        e[i].k = i;
    }
    sort(e , e + n - 1 , cmp);
    ll j;
    for (ll i = 0 ; i < n - 1 ; i = j){
        for (j = i ; j < n - 1 and e[i].w == e[j].w ; j ++);

        for (ll k = 0;  k < frnt ; k ++){
            vec[k].clear();
            vec2[k].clear();
        }
        mp.clear();
        frnt = 0 ;
        for (ll k = i ; k < j ; k ++){
            getpar(e[k].x);
            if(mp.count(par[e[k].x]) == 0){
                mp[par[e[k].x]] = frnt;
                c[frnt] = val[par[e[k].x]];
                frnt ++;
            }
            getpar(e[k].y);
            if(mp.count(par[e[k].y]) == 0){
                mp[par[e[k].y]] = frnt;
                c[frnt] = val[par[e[k].y]];
                frnt ++;
            }
            ll x = mp[par[e[k].x]] , y = mp[par[e[k].y]];
            vec[x].pb(y);
            vec[y].pb(x);
            vec2[x].pb(e[k].k);
            vec2[y].pb(e[k].k);
        }
        for (ll k = 0 ;k < frnt ; k++){
            mark[k] = 0;
        }
        for (ll k = 0 ;k < frnt ; k ++){
            if(mark[k] == 0){
                s = 0 ;
                dfs(k);
                s1 = 0;
                dfs2(l ,  -1);
            }
        }
        for (ll k = i ; k < j ; k ++){
            merge(e[k].x , e[k].y);
        }
    }
    s = 0;
    for (ll i = 0 ; i < n ; i ++){
        s = max(s ,res[i]);
    }
    ll cnt = 0 ;
    for (ll i = 0; i < n ; i  ++){
        if(res[i] == s){
            cnt++;
        }
    }
    cout << s+s << ' ' << cnt << endl;
    for (ll  i= 0 ; i < n ; i ++){
        if(res[i] == s){
            cout << i + 1 << ' ';
        }
    }
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
