#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5;
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

ll n;
vector < ll > vec[maxn];
bool mark[maxn];
ll dist[maxn];
queue < ll > q;
map <pll , bool > mp;
ll ans = 0;
ll par[maxn];

void dfs(ll v){
    mark[v] = 1;
    for (ll u : vec[v]){
        if(!mark[u]){
            dist[u] = dist[v] + 1;
            par[u] = v;
            dfs(u);
        }
    }
}

int main(){
    migmig
    cin >> n;
    for (ll i = 1 ; i < n ; i ++){
        ll u , v;
        cin >> v >> u;
        vec[u].pb(v);
        vec[v].pb(u);
    }
    //find diam;
    dist[1] = 0;
    dfs(1);
    ll sar = 1;
    for (ll i = 2 ; i<= n ; i ++){
        if(dist[i] > dist[sar]){
            sar = i;
        }
    }
    ms(mark , 0);
    par[sar] = -1;
    dfs(sar);
    ll tah = sar;
    for (ll i = 1 ; i<= n ; i ++){
        if(dist[i] > dist[tah]){
            tah = i;
        }
    }
    ll boz = sar;
    ms(mark , 0);
    ms(dist , 0);
    ll pos = tah;
    while(pos!=-1){
        q.push(pos);
        dist[pos] = 0;
        mark[pos] = 1;
        pos = par[pos];
    }
    while(!q.empty()){
        ll v = q.front() ;
        q.pop();
        for (ll u : vec[v]){
            if(!mark[u]){
                dist[u] = dist[v] + 1;
                boz = u;
                mark[u] = 1;
                if(dist[u] > dist[boz]) boz = u;
                q.push(u);
            }
        }
    }
    if (boz == sar or boz == tah){
        for (int i = 1 ; i <= n ; i ++){
            if(i!=sar and i!=tah){
                boz = i;
                break;
            }
        }
    }
    ms(mark, 0 );
    ms(dist , 0);
    par[sar] = -1;
    dfs(sar);
    pos = tah;
    while(par[pos]!=-1){
        if(mp[pii(pos , par[pos])] == 0){
            ans++;
            mp[pii(pos , par[pos])] = mp[pii(par[pos] , pos)] = 1;
        }
        pos = par[pos];
    }
    pos = boz;
    while(par[pos]!=-1){
        if(mp[pii(pos , par[pos])] == 0){
            ans++;
            mp[pii(pos , par[pos])] = mp[pii(par[pos] , pos)] = 1;
        }
        pos = par[pos];
    }
    ms(mark, 0 );
    ms(dist , 0);
    par[boz] = -1;
    dfs(boz);
    pos = tah;
    while(par[pos]!=-1){
        if(mp[pii(pos , par[pos])] == 0){
            ans++;
            mp[pii(pos , par[pos])] = mp[pii(par[pos] , pos)] = 1;
        }
        pos = par[pos];
    }
    cout << ans << endl;
    cout << sar << ' ' << tah << ' ' << boz;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.