#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6+100;
const ll mod = 998244353;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}


int n , m;
ll fact[maxn];

ll ent(ll a , ll b){
    return(((fact[b] * pw(fact[a] , mod - 2 , mod) % mod )*pw(fact[b - a] , mod - 2 ,mod)%mod )%mod);
}

int main(){
    migmig
    cin >> n >> m;
    fact[0] = 1;
    for (int i  = 1 ; i <= (int)2e5+100 ; i ++){
        fact[i] = fact[i - 1]*i%mod;
    }
    ll ans = ((n - 2)*ent(n - 1 , m))%mod;
    ans = (pw(2 , n - 3) * ans)%mod;
    cout << ans;




    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
