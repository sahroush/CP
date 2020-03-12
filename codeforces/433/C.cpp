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

int n , m;
int a[maxn];
vector < int > vec[maxn];

int main(){
    migmig
    cin >> n >> m ;
    for (int i = 0 ; i < m ; i ++){
        cin >> a[i];
    }
    ll sum = 0 ;
    for (int i = 0 ; i < m - 1 ; i ++){
        sum += abs(a[i] - a[i + 1]);
    }
    for (int i = 0 ; i < m ; i ++){
        if(i and a[i]!=a[i - 1]){
            vec[a[i]].pb(a[i - 1]);
        }
        if(i < m-1 and a[i + 1] != a[i]){
            vec[a[i]].pb(a[i + 1]);
        }
    }
    ll ans = sum;
    for (int i = 1 ; i <= n ; i ++){
        if(vec[i].size()){
            sort(vec[i].begin() , vec[i].end());
            ll mid = vec[i][vec[i].size()/2];
            ll pre = 0 , cur = 0;
            for(auto j : vec[i]){
                pre+=abs(i - j);
                cur+=abs(j - mid);
            }
            ans = min(ans , sum - pre + cur);
        }
    }
    cout << ans ;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
