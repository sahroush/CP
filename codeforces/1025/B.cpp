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
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n;
ll a[maxn] , b[maxn] , c[maxn];

int main(){
    migmig
    cin >> n;
    ll ans ;
    for (int i = 0;  i < n ; i ++){
        cin >> a[i] >> b[i];
        c[i] = a[i]*b[i];
    }
    ans = c[0];
    for (int i =  1 ; i < n ; i ++){
        ans = __gcd(ans , c[i]);
    }
    for (int i = 0 ; i < n ; i ++){
        if(__gcd(ans , a[i] ) != ans and __gcd(ans , b[i]) != ans){
            ans = max(__gcd(ans , a[i]) , __gcd(ans , b[i]));
        }
    }
    if(ans == 1){
        dokme(-1);
    }
    cout << ans;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.