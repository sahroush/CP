#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e5;
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

ll n , m , l , r;

int main(){
    migmig
    cin >> n >> m >> l >> r;
    if(n > m){
        swap(n , m);
    }
    if(l-r == 0){
        dokme(1);
    }
    ll odd , even;
    if(l%2){
        even = (r-l+1)/2;
        odd = (r-l+1)-even;
    }
    else{
        odd = (r-l+1)/2;
        even = (r-l+1)-odd;
    }
    ll ans = 0;
    if(n*m%2){
        ans = (ans + pw((r - l + 1) , n*m))%mod;
        dokme(ans%mod)
    }
    ans = (ans + pw((r - l + 1) , n*m))%mod;
    ll res;
    res+=pw((r - l+1) , n*m);
    res-=pw((odd - even) , n*m);
    res+=ll(100)*mod;
    res%=mod;
    res = res*pw(2 , mod-2)%mod;
    ans-=res;
    ans+=ll(100)*mod;
    dokme(ans%mod)
    //akhe in kojash ghalate :/
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
