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

int n,a[maxn];
ll cnt[maxn];
ll ans;

int sz[maxn];
bool good[maxn] , mark[maxn];
vector < int > dv[maxn];

int main(){
    migmig
    cin >> n;
    for(int i = 0 ;  i < n ; i ++){
        cin >> a[i];
        for(int j = 1 ; j*j <= a[i] ; j ++){
            if(a[i]%j==0){
                cnt[j]++;
                if(a[i]/j!=j){
                    cnt[a[i]/j]++;
                }
            }
        }
    }
    ans = 0;
    int k = 1e5+5;
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
    good[1] = 1;
    for(int i = 1 ; i <= k ; i ++){
        if(!good[i]){
            continue;
        }
        ll val = (pw(2 , cnt[i])-1+mod)%mod;
        if(sz[i]%2){
            val*=-1;
        }
        ans = (ans + val + (ll)10*mod)%mod;
    }
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
