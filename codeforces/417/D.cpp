#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 5e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , m , b;
ll dp[(1 << 20)];
ll monitor[(1 << 20)];

struct frnd{
    ll prc ,mntr;
    int tasks;
}fr[maxn];

bool cmp (frnd i , frnd j){
    return(i.mntr < j.mntr);
}

int main(){
    migmig
    cin >> n >> m >> b;
    for(int i =  1 ; i <= n ;  i ++){
        cin >> fr[i].prc;
        cin >> fr[i].mntr;
        int x = 0 ;
        cin >> x;
        int val=0;
        for(int j = 0; j < x; j ++){
            int inp;
            cin >> inp;
            inp -- ;
            val|=(1<<inp);
        }
        fr[i].tasks = val;
    }
    sort(fr+1, fr + n+1 , cmp);
    ms(dp , 63);
    dp[0] = 0;
    ll ans = dp[1];
    for(int j = 1; j <= n ; j ++){
        for(int i = 0 ; i < (1 << m)-1 ; i ++){
            ll boz =dp[i|fr[j].tasks];
            dp[i|fr[j].tasks] = min(dp[i|fr[j].tasks] , dp[i] + fr[j].prc);
        }
        if(dp[(1 << m)-1]!=ans){
            ans = min(ans , dp[(1 << m)-1] + b * fr[j].mntr);
        }
    }
    dp[(1 << m) - 1] = ans;
    ll maxval[2];
    ms(maxval , 63);
    if(dp[(1 << m)-1] == maxval[0]){
        dokme(-1);
    }
    cout << dp[(1 << m)-1];
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
