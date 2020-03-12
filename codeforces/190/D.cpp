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

int n , k;
int l , r;
int a[maxn];
map <int , int > mp;
ll ans = 0;

int main(){
    migmig
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++){
        cin >> a[i];
    }
    r = l = 0;
    mp[a[r]]++;
    while(l < n and r < n){
        if(mp[a[r]] >= k){
            ans+=(n - r);
            mp[a[l]]--;
            l++;
        }
        else{
            r++;
            mp[a[r]]++;
        }
    }
    cout << ans;


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
