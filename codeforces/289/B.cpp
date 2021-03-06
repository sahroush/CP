#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int ,int > pii;

const ll maxn =2e5+10;
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

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

ll n , m , d , mn = 1e5;
ll a[maxn];

ll chk(ll x){
    ll cnt = 0;
    for (ll  i  =0 ; i < m * n ; i ++){
        cnt += abs(a[i] - x);
    }
    return(cnt);
}

int main(){
    migmig
    cin >> n >> m >> d;
    for (ll i = 0 ; i < n * m ; i ++){
        cin >> a[i];
        mn = min(mn , a[i]);
        if (a[i]%d != a[0]%d){
            dokme(-1);
        }
    }
    for (ll i = 0 ; i < n * m ; i ++){
        a[i]/=d;
    }
    ll l = 0 , r = 1e13;
    while(r - l > 1){
        ll mid = (l+r) / 2;
        ll c1 = chk(mid) , c2 = chk(mid+1);
        if(c1 > c2){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << chk(r);
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
