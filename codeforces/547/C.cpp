#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =6e5;
const ll mod = 1e9+7;//998244353;
const ld PI = 4 * atan((ld) 1);
const int mods[] = {998244353, 1000000007, 696969569, 1000000009, 998244853};
const int rmod = mods[rng()%5];
const int rmod2 = mods[rng()%5];

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = rmod) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

vector < ll > mg[maxn];
ll a[maxn];
ll n , q;
bool mark[maxn];
ll val[maxn];
ll prm[maxn];
ll ans = 0 , sz = 0;
ll mp[maxn];

void add(ll x){
    ll num = a[x];
    ll n = mg[num].size();
    val[x] = sz-1;
    for (int i = 1 ; i < pw(2 , n) ; i ++){
        ll prd = 1;
        ll cnt = 0;
        for (int j = 0 ; j < n ; j++){
            if(i & (1<<j)){
                prd*=(mg[num][j]);
                cnt++;
            }
        }
        if(cnt%2){
            val[x] -= mp[prd];
        }
        else{
            val[x]+=mp[prd];
        }
        mp[prd]++;
    }
    ans+=val[x];
}
void remove(int x){
    ll num = a[x];
    ll n = mg[num].size();
    val[x] = sz;
    for (int i = 1 ; i < pw(2 , n) ; i ++){
        ll prd = 1;
        ll cnt = 0;
        for (int j = 0 ; j < n ; j++){
            if(i & (1<<j)){
                prd*=(mg[num][j]);
                cnt++;
            }
        }
        mp[prd]--;
        if(cnt%2){
            val[x] -= mp[prd];
        }
        else{
            val[x]+=mp[prd];
        }
    }
    ans-=val[x];
}

int main(){
    migmig
    assert(dominance);
    for (int i = 2 ; i < maxn ; i ++){
        if(mg[i].empty()){
            for (int j = i ; j < maxn ; j += i){
                mg[j].pb(i);
            }
        }
    }
    cin >> n >> q;
    for (int i = 1 ;i <= n ; i ++){
        cin >> a[i];
    }
    while(q--){
        ll x;
        cin >> x;
        mark[x] = !mark[x];
        if(mark[x]){
            if(a[x] == 1){
                ans+=sz;
            }
            sz++;
            if(a[x]!=1){
                add(x);
            }
        }
        else{
            sz--;
            if(a[x] == 1){
                ans -= sz;
            }
            if(a[x]!=1){
                remove(x);
            }
        }
        cout << ans << endl;
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
