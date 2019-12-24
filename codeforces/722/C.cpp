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
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << '\n';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

ll n;
ll a[maxn];
ll p[maxn];
ll sum[maxn];
ll par[maxn] , sz[maxn];
bool mark[maxn];
ll mx = 0;
vector <ll> ans;

ll getpar(ll v){
    if(v == par[v]){
        return(v);
    }
    return(par[v] = getpar(par[v]));
}
void merge(ll x , ll y){
    x = getpar(x) , y = getpar(y);
    if(x == y){
        return;
    }
    if(sz[y] > sz[x]){
        swap(x , y);
    }
    sz[x] += sz[y];
    sum[x]+=sum[y];
    mx = max(mx , sum[x]);
    par[y] = x;
}

int main(){
    migmig
    cin >> n ;
    for (ll  i = 1 ; i <= n ; i ++){
        cin >> a[i];
        par[i] = i;
        sum[i] = a[i];//
        sz[i] = 1;
    }
    for (ll i  = 1; i <= n ; i ++){
        cin >> p[i];
    }
    reverse(p + 1, p + n + 1);
    for (ll i = 1 ; i <= n ; i ++){
        ans.pb(mx);
        mark[p[i]] = 1;
        if(p[i] + 1 <= n){
            if(mark[p[i] + 1]){
                merge(p[i] , p[i] + 1);
            }
        }
        if(p[i] - 1 >= 1){
            if(mark[p[i] - 1]){
                merge(p[i] , p[i] - 1);
            }
        }
        mx = max(mx , (ll)a[p[i]]);
    }
    reverse(ans.begin() , ans.end());
    prnt(ans);


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
