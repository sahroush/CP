#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
const ll mod = 1e9+7;//998244353;
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

int n , x;
ld p[200];
ld dp[200][200];
ld ans[200][2];

int main(){
    migmig
    cin >> n >> x;
    for (int i = 1 ; i <= x+1 ; i ++){
        cin >> p[i];
        dp[i-1][0] = p[i];
    }
    for(int i = 1 ; i < 32 ; i ++){
        for (int j = 0 ; j < 128 ; j ++){
            for (int k = 0 ; k < 128 ; k ++){
                dp[j^k][i]+=dp[j][i - 1]*dp[k][i - 1];
            }
        }
    }
    ans[0][0] = 1;
    bool f = 0;
    for (int i = 0 ; i < 32 ; i ++){
        if(n & (1<<i)){
            f = !f;
            for (int j = 0 ;j < 200 ; j ++){
                ans[j][f]  = 0;
            }
            for (int j = 0;  j < 128 ; j ++){
                for (int k = 0 ; k < 128 ; k ++){
                    ans[j^k][f] += dp[k][i] * ans[j][!f];
                }
            }
        }
    }
    cout << fixed << setprecision(10) << ld(1)-ans[0][f];



    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
