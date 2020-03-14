#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =2e6;
const ll mod = 1e9+7;//998244353;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

ll n , m;
ll ans = 0;

int main(){
    migmig
    cin >> n >> m;
    ans = (n%mod)*(m%mod)%mod;
    ans%=mod;
    ll sum= 0;
    for (ll i = 1; i <=m ; i ++){
        if(n/i == 0){
            break;
        }
        ll l = i;
        ll r =min(m , n / (n/ll(i)));
        if ((r - l +1)%2){
                sum += (l + r)/2%mod*((r - l + 1) %mod * (n / ll(i))%mod)%mod;
        }
        else{
            sum += (r - l + 1)/2%mod*((r + l) %mod * (n / ll(i))%mod)%mod;
        }
        sum%=mod;
        i = r;
    }
    cout << (ans - sum +(100)*mod)%mod;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
