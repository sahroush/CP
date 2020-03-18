#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn =2e6+1000;
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
    //return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
    ll res = 1;
    while(b){
        if(b&1){
            res=(a*res)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return(res);
}

int n , k;
int pww[maxn];
int sz[maxn];
bool good[maxn] , mark[maxn];
vector < int > dv[maxn];

int main(){
    migmig
    cin >> n >> k;
    for (int i = 1 ; i <= k ; i ++){
        pww[i] = pw(i , n);
    }
    for (int i = 2 ; i <= k; i ++){
        if(!mark[i]){
            for (int j = i ; j<= k ; j += i ){
                sz[j]++;
                if(!mark[j]){
                    good[j] = 1;
                }
                if(j%(i*i) == 0){
                    good[j] = 0;
                }
                mark[j] = 1;
                dv[j].pb(i);
            }
        }
        else{
            for (int j = i ; j <= k ; j += i){
                dv[j].pb(i);
            }
        }
    }
    for (int j = 1 ; j <= k ; j ++){
        dv[j].pb(1);
    }
    ll sum = 0 , res = 0;
    good[1] = 1;
    for (int i = 1; i <= k ; i ++){
        for (auto v : dv[i]){
            ll boz = pww[i/v] - pww[i/v-1];
            if(!good[v]){
                boz = 0;
            }
            if(sz[v]%2){
                boz*=-1;
            }
            sum+=boz;
            sum%=mod;
        }
        sum = sum+mod*(ll)10;
        sum%=mod;
        res += (sum^i)%mod;
        res%=mod;
    }
    cout << res;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
