#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =4e5;
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

ll n , m , ta , tb , k;
vector <ll>  a , b;

ll bound(ll x){
    ll l = 0 , r = b.size() - 1;
    while(r - l > 1){
        ll mid = (l + r) / 2;
        if(b[mid] >= x){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    if(b[r] >= x){
        return(r);
    }
    return(-1);
}

int main(){
    migmig
    ll inp;
    ll mn = 1e9+1;
    cin >> n >> m >> ta >> tb >> k;
    for (ll i = 0;  i < n ; i ++){
        cin >> inp;
        a.pb(inp);
        mn = min(mn , inp);
    }
    ll mx = -1;
    for (ll i = 0 ; i < m ; i ++){
        cin >> inp;
        if(inp >= mn + ta){
            b.pb(inp);
            mx = max(mx , inp);
        }
    }
    while(a.size()){
        if(a.back() +ta > mx ){
            a.pop_back();
        }
        else{
            break;
        }
    }
    if(b.size() <= k or a.size() <= k){
        dokme(- 1);
    }
    ll ans=0;
    for(int i=0;i<=k;i++){
        int j=lower_bound(b.begin(),b.end(),a[i]+ta)-b.begin();
        j+=k-i;
        if(j<m)
            ans=max(ans,b[j]+tb);
        else{
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
