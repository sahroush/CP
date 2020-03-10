#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
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

int n;
int a[maxn];
ll dp[maxn];
ll ent[2000][2000];

int main(){
    migmig
    cin >> n;
    for (int i = 0 ; i < 2000 ; i ++){
        ent[i][i] = ent[i][0]  =1;
        for (int j = 1 ;j < i ; j ++){
            ent[i][j] = (ent[i - 1][j - 1] + ent[i-1][j])%mod;
        }
    }
    for (int i = 0 ; i < n ; i ++){
        cin >> a[i];
    }
    dp[n] = 1;
    ll ans = 0;
    for (int i = n-1 ; i >= 0 ; i --){
        if(i + a[i] <= n and a[i] > 0){
            for (int j  = i + a[i] +1 ; j <= n ; j ++){
                dp[i] += (dp[j] * ent[j - i - 1][a[i]])%mod;
                dp[i]%=mod;
            }
        }
        ans+=dp[i];
        ans%=mod;
    }
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
