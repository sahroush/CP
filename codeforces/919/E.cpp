#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e3+100;//AmShZ
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define lowbit(x) ((x)&(-(x)))
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);
}

ll a , b , p , x;
ll ans = 0;

int main(){
    migmig
    cin >> a >> b >> p >> x;
    ll cur;
    ll pow_a = 1;
    for(int i = 0 ; i < p-1 ; i ++){
        cur = (i - b * pw(pow_a , p-2, p))%p;
        cur+=(ll)100*p;
        cur%=p;
        ll l = cur;
        ll r = (x - i)/(p-1);
        ll res = (r - l)/p + 1;
        if(!i and !l){
            res--;
        }
        if(r < l or res < 0 or x < i){
            res = 0;
        }
        ans+=res;
        pow_a = (pow_a*a)%p;
    }
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
