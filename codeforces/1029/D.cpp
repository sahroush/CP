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
    ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);
}

ll n , k;
map < ll , ll > cnt[20];
ll a[maxn];
ll l[maxn];
ll p[20];

ll len(ll x){
    ll ans = 0;
    while(x){
        x/=10;
        ans++;
    }
    return(ans);
}

int main(){
    migmig
    cin >> n >> k;
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i];
        l[i] = len(a[i]);
        cnt[l[i]][a[i]%k]++;
    }
    ll ans = 0;
    for(int i = 0 ; i < 15 ; i ++){
        p[i] = pw(10 , i , k);
    }
    for(int i = 0 ; i < n ; i ++){
        for(int j = 1 ; j <= 10; j ++){
            ll num = (a[i] * p[j])%k;
            num = (k - num)%k;
            ans+=cnt[j][num];
            if(j == l[i] and num == a[i]%k){
                ans--;
            }
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
