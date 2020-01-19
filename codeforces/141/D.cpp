#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
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

struct ramp{
    ll x , d , t , p , id;
};
struct edg{
    ll u , v , w;
    //preconstructor
    edg(ll x , ll y , ll z):u(x),w(y),v(z){};
};

vector< edg > adj[maxn];
vector<ramp> rmp;
ll par[maxn] , dist[maxn] , ed[maxn];

bool mark[maxn];
vector <ll> vec , ans;
ll n , l;
set <pll> st;
map <ll , ll > pos;

bool cmp(ramp i , ramp j){
    return(i.x<=j.x);
}

void djk(ll s){
    dist[s] = 0;
    par[s] = -1;
    st.insert(pii(dist[s] , s));
    while(!st.empty()){
        auto v = *st.begin();
        st.erase(v);
        if(mark[v.second]) continue;
        mark[v.second ]= 1;
        for (auto u : adj[v.second]){
            if(dist[u.u] > dist[v.second] + u.w){
                par[u.u] = v.second;
                ed[u.u] = u.v;
                dist[u.u] = dist[v.second] + u.w;
                st.insert(pii(dist[u.u] , u.u));
            }
        }
    }
}

int main(){
    migmig
    cin >> n >> l;
    vec.pb(0);
    vec.pb(l);
	for (ll i = 1 ; i <=n ; i ++){
        ll x , d , t , p;
        cin >> x >> d >> t >> p;
        if(x - p < 0 or t>= d){
            continue;
        }
        ramp boz;
        boz.x = x;
        boz.d = d;
        boz.t = t;
        boz.p = p;
        boz.id = i;
        rmp.pb(boz);
        vec.pb(x - p);
        vec.pb(x + d);
    }
	sort(vec.begin() , vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	ll sz = vec.size();
	ll m = sz - 1;
    assert(sz < 2e6);
    for (ll i = 1 ; i < sz ; i ++){
        pos[vec[i]] = i;
        ll dst = vec[i] - vec[i - 1];
        adj[i].pb(edg(i-1 , dst , 0));
        adj[i - 1].pb(edg(i , dst , 0));
    }
    ms(dist , 63);
	sort(rmp.begin(),rmp.end() , cmp);
	n = sz = rmp.size();
    for (ll i = 0 ; i < sz ; i ++){
        ll from , to , t , indx;
        from = rmp[i].x - rmp[i].p, to = rmp[i].d  + rmp[i].x, t = rmp[i].t+rmp[i].p , indx = rmp[i].id;
        adj[pos[from]].pb(edg(pos[to] , t , indx));
    }
	djk(0);

	ll ans1 = dist[m] , boz = m;

    while (boz != -1){
        if(ed[boz]){
            ans.pb(ed[boz]);
        }
        boz = par[boz];
    }
    cout << dist[m] << endl;
    cout << ans.size() << endl;
    //reverse(ans.begin() , ans.end());
    while(!ans.empty()){
        cout << ans.back() << ' ';
        ans.pop_back();
    }
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
