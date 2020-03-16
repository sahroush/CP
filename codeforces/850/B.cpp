#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =1e6+10;
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

ll n , x , y , a[maxn];
ll val[maxn] , cnt[maxn] , prt[maxn];

int main(){
    migmig
    cin >> n >> x >> y;
    for (ll i =0 ;  i < n ; i ++){
        cin >> a[i];
        prt[a[i]]+=a[i];
        cnt[a[i]]++;
    }
    for(ll i = 1 ; i < maxn ; i ++){
        prt[i]+=prt[i - 1];
        cnt[i]+=cnt[i - 1];
    }
    ll ans = 1e18;
    for (ll i = 2 ; i <= (ll)1000000 ; i ++){
        ll act = min(ll(x/y) , i-1);
        ll sum = 0;
        for (ll j = 0 ; j <= (ll)1000000 ; j += i){
            sum += x*(cnt[min(i + j - act-1 , (ll)1000000 )] - cnt[j]);
            ll diff = cnt[min(i + j  - 1 , (ll)1000000)] - cnt[min((ll)1000000 , i + j - act-1)];
            ll sdif = prt[min(i + j  - 1 , (ll)1000000)] - prt[min((ll)1000000 , i + j - act-1)] - j * diff;
            sdif = i * diff - sdif;
            sum += sdif*y;
        }
        ans = min(ans , sum);
    }
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
