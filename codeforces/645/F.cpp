#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =1e6+1000;
const ll mod = 1e9+7;//998244353;
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

int n , k , q;
ll ans = 0;
vector<int> mg[maxn];
ll cnt[maxn];
ll fact[maxn] , inv[maxn];
ll val[maxn];

ll ent(ll r , ll n){
    if(r > n) return(0);
    return((fact[n] * inv[n - r]%mod *inv[r]%mod)%mod);
}

int main(){
    migmig
    inv[0] = fact[0] = 1;
    for (int i =  1 ; i < maxn ; i ++){
        fact[i] = (fact[i - 1]*i)%mod;
        inv[i] = pw(fact[i] , mod-2);
        val[i] = i;
    }
    for(int i = 1 ; i < maxn ; i ++){
        for (int j = i ; j < maxn ; j += i){
            mg[j].pb(i);
            val[j]-=val[i]*(bool)(j-i);
        }
    }
    cin >> n >> k >> q;
    for (int i = 0 ; i < n ; i ++){
        int inp;
        cin >> inp;
        for (int j : mg[inp]){
            ans-= (ent(k , cnt[j]))*(val[j])%mod;
            ans+=mod*(ll)100;
            ans%=mod;
            ans+=(ent(k , ++cnt[j]))*(val[j])%mod;
            ans%=mod;
        }
    }
    for (int i = 0 ; i < q ; i ++){
        int inp;
        cin >> inp;
        for (int j : mg[inp]){
            ans-= (ent(k , cnt[j]))*(val[j])%mod;
            ans+=mod*(ll)100;
            ans%=mod;
            ans+=(ent(k , ++cnt[j]))*(val[j])%mod;
            ans%=mod;
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
