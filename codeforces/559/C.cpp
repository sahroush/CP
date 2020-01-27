#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5+5;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

ll fact[maxn];ll mdinv[maxn];
ll ent(ll r , ll n){
    if(r>n or r<0 or n<0) return(0);
    return((fact[n] * mdinv[r]%mod * mdinv[n - r] % mod)%mod);
}

ll calc(pll a , pll b){
    return(ent(b.first - a.first,b.first + b.second - a.first - a.second)%mod);
}

int n;
pll p[maxn];
ll dp[maxn];


int main(){
    migmig
    mdinv[0] = fact[0] = 1;
    for (int i = 1 ; i <= 500001 ; i ++){
        fact[i] = i*fact[i - 1];
        fact[i]%=mod;
        mdinv[i] = pw(fact[i] , mod - 2)%mod;
    }

    cin >> p[0].first >> p[0].second;
    cin >> n;
    for (int i = 1 ; i <= n ; i ++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p , p + n + 1);

    dp[0] = calc(pll(1 , 1) , p[0]);

    for (int i = 1 ; i <= n ; i ++){
        dp[i] = calc(pll(1 , 1) , p[i]);
        for (int j = 0 ; j < i ; j ++){
            dp[i] -= ((dp[j] * calc(p[j] , p[i]))%mod);
            dp[i] = (dp[i] + mod*mod)%mod;
        }
    }
    cout << dp[n];
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
