#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;//AmShZ
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int n , k;
int cnt2[maxn] , cnt5[maxn];
int dp[210][210*30];

int main(){
    migmig
    cin >> n >> k;
    ms(dp , -63);
    dp[0][0]=0;
    for(int i = 1 ; i <= n ; i ++){
        ll x;
        cin >> x;
        while(x%2 == 0){
            x/=2;
            cnt2[i]++;
        }
        while(x%5 == 0){
            x/=5;
            cnt5[i]++;
        }
        for(int j = min(i , k) ; j>0 ; j --){
            for(int h = 0 ; h < 30*j ; h ++){
                dp[j][h + cnt5[i]] = max(dp[j][h + cnt5[i]] , dp[j - 1][h]+cnt2[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0;  i < n*28 ; i ++){
        ans = max(ans , min(i , dp[k][i]));
    }
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
