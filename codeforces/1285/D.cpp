#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =2e6;
const ld SADAT = 7.84e-17;
const ll INF = 1e18;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define all(x) x.begin() , x.end()
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

bitset < 40 > a[maxn] , xr;
ll inp[maxn];
ll n;

ll solve(ll l , ll r , ll pos){
    if(r == l  or pos < 0){
        return(0);
    }
    ll ps = r;
    for (ll i = l ; i <= r ; i ++){
        if(a[i][pos] == 1){
            ps = i - 1;
            break;
        }
    }
    //cout << l << ' ' << ps << endl;
    if(ps ==l-1 or ps == r){
        return(solve(l , r , pos-1));
    }
    return(min(solve(l, ps , pos - 1), solve(ps + 1, r, pos - 1))+(ll) pw(2 , pos));
}

int main(){
    migmig
    cin >> n;
    for (ll i = 1 ; i <= n ; i ++){
        cin >> inp[i];
    }
    sort(inp +1 , inp + n +1);
    //reverse(inp , inp + n);
    for (ll i = 1 ; i <= n ; i ++){
        a[i] = inp[i];
        //cout << a[i] << endl;
    }
    cout << solve(1 , n , 35);


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
