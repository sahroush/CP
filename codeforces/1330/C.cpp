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

ll n , m;
ll ans[maxn];
ll l[maxn];
ll mx[maxn];
ll sz[maxn];
ll sum = 0;
ll las[maxn];
bool col[maxn];

int main(){
    migmig
    cin >> n >> m;
    for(int i = 1; i <= m ; i ++){
        cin >> l[i];
        mx[i] = n - l[i] + 1;
        sz[i] = l[i]-1;
        sum+=l[i];
        if(n - l[i] < i-1){
            dokme(-1);
        }
    }
    if(sum < n){
        dokme(-1);
    }
    for(int i = 1 ; i <= m ; i ++){
        ans[i] = i;
        las[i] = max(las[i - 1] , i + sz[i]);
    }
    ll cnt = n;
    for(int i = 1 ; i <= las[m] ; i ++){
        col[i] = 1;
        cnt--;
    }
    ll lst = n;
    for(int i = m ; i >= 1 ; i--){
        if(cnt > 0){
            ans[i]=lst-sz[i];
            for(int j = las[i] ; j > las[i - 1] ; j --){
                col[i]=0;
                cnt++;
            }
            for(int j = lst ; j >= lst-sz[i];j--){
                col[i] = 1;
                cnt--;
            }
            lst-=l[i];
        }
    }
    for(int i = 1 ; i <= m ; i ++){
        cout << ans[i] << ' ';
    }


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
